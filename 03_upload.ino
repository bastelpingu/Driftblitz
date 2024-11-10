// OTA Upload Handler
void handleUpdate(AsyncWebServerRequest *request) {
  request->send(200);
}

// Check if there is enough space available for the update
void handleUpdateUpload(AsyncWebServerRequest *request, const String &filename, size_t index, uint8_t *data, size_t len, bool final) {
  if (!index) {
    size_t totalSize = request->contentLength();
    Serial.printf("Update started: %s\n", filename.c_str());
    ws.textAll("Update started: " + filename);  // Output to the browser monitor

    if (totalSize > ESP.getFreeSketchSpace()) {
      Serial.println("Not enough space for the update.");
      ws.textAll("Not enough space for the update.");
      request->send(500, "text/plain", "Not enough space");
      return;
    }

    if (!Update.begin(totalSize)) {  // Start the update with the known size
      Update.printError(Serial);
      ws.textAll("Update error!");  // Output to the browser monitor
      request->send(500, "text/plain", "Update error");
      return;
    }
  }

  // Calculate progress and only output if changed
  size_t progress = (index + len) * 100 / request->contentLength();
  unsigned long currentTime = millis();
  if (progress != lastProgress && currentTime - lastWebSocketMessageTime > messageInterval) {
    lastProgress = progress;
    lastWebSocketMessageTime = currentTime;
    ws.textAll("Progress: " + String(progress) + "%");  // Output to the browser monitor
  }

  // Write data
  if (Update.write(data, len) != len) {
    Update.printError(Serial);
    ws.textAll("Error writing the file!");
    request->send(500, "text/plain", "Error writing the file");
    return;
  }

  // If the upload is complete
  if (final) {
    if (Update.end(true)) {
      delay(300);                                           // Update successfully completed
      ws.textAll("Update complete. ESP32 is restarting.");  // Output to the browser monitor
      Serial.printf("Update complete: %u bytes\n", index + len);
      delay(1000);
      ESP.restart();
    } else {
      Update.printError(Serial);
      ws.textAll("Update failed!");
      request->send(500, "text/plain", "Update failed");
    }
  }
}

// Handle WebSocket events
void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
               void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.println("WebSocket connected");

    // Send the current value of distanceLED to the client
    {
      StaticJsonDocument<64> response;
      response["type"] = "currentDistanz";
      char valueStr[16];
      snprintf(valueStr, sizeof(valueStr), "%.2f", distanzLED);
      response["value"] = valueStr;
      String responseString;
      serializeJson(response, responseString);
      client->text(responseString);
    }

    // Send the current pin settings
    {
      StaticJsonDocument<128> response;
      response["type"] = "currentPins";
      response["ledPin"] = LED_PIN;
      response["sclPin"] = SCL_PIN;
      response["sdaPin"] = SDA_PIN;
      String responseString;
      serializeJson(response, responseString);
      client->text(responseString);
    }

    // Send the current WiFi settings (SSID and password)
    {
      StaticJsonDocument<128> wifiResponse;
      wifiResponse["type"] = "currentWifi";
      wifiResponse["ssid"] = ssid;
      wifiResponse["password"] = password;  // Send the password in plain text
      String wifiResponseString;
      serializeJson(wifiResponse, wifiResponseString);
      client->text(wifiResponseString);
    }
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("WebSocket disconnected");
  } else if (type == WS_EVT_DATA) {
    AwsFrameInfo *info = (AwsFrameInfo *)arg;

    if (info->opcode == WS_TEXT) {
      String msg = "";
      // Assemble the message
      for (size_t i = 0; i < len; i++) {
        msg += (char)data[i];
      }

      // Wenn die Nachricht vollständig ist
      if (info->final) {
        Serial.println("Received message: " + msg);

        // Try to parse the message as JSON
        StaticJsonDocument<256> doc;
        DeserializationError error = deserializeJson(doc, msg);
        if (!error) {
          const char *type = doc["type"];
          if (strcmp(type, "setDistanz") == 0) {
            // Handling for setting the distance
            float value = doc["value"].as<float>();
            distanzLED = value;

            // Store the new value in non-volatile storage
            preferences.putFloat("distanzLED", distanzLED);

            Serial.printf("Distance set to: %.2f cm\n", distanzLED);
            // Send confirmation to the client
            StaticJsonDocument<64> response;
            response["type"] = "distanzSet";
            char valueStr[16];
            snprintf(valueStr, sizeof(valueStr), "%.2f", distanzLED);
            response["value"] = valueStr;
            String responseString;
            serializeJson(response, responseString);
            client->text(responseString);
          } else if (strcmp(type, "setPins") == 0) {
            // Handling for setting the pins

            // **1. Stop sensor if initialized**
            if (sensorInitialized) {
              sensor.stopContinuous();    // Stop continuous sensor operation
              sensorInitialized = false;  // Update sensor status
              Serial.println("Sensor stopped before pin change.");
            }

            // **2. Read new pin values from the message**
            int newLEDPin = doc["ledPin"];
            int newSCLPin = doc["sclPin"];
            int newSDAPin = doc["sdaPin"];

            Serial.printf("New pin settings received - LED_PIN: %d, SCL_PIN: %d, SDA_PIN: %d\n", newLEDPin, newSCLPin, newSDAPin);

            // **3. Store the new values in non-volatile storage**
            preferences.putInt("LED_PIN", newLEDPin);
            preferences.putInt("SCL_PIN", newSCLPin);
            preferences.putInt("SDA_PIN", newSDAPin);

            // **4. Update the variables in the running program**
            LED_PIN = newLEDPin;
            SCL_PIN = newSCLPin;
            SDA_PIN = newSDAPin;

            // **5. Update pin modes**
            pinMode(LED_PIN, OUTPUT);    // Set the new LED_PIN to OUTPUT
            digitalWrite(LED_PIN, LOW);  // Ensure the LED is off

            // **6. Update the I2C pins**
            Wire.end();                    // End the current I2C connection
            Wire.begin(SDA_PIN, SCL_PIN);  // Start the I2C connection with the new pins
            Serial.println("I2C connection initialized with new pins.");

            // **7. Send confirmation to the client**
            StaticJsonDocument<64> response;
            response["type"] = "pinsSet";
            response["status"] = "success";
            String responseString;
            serializeJson(response, responseString);
            client->text(responseString);

            // **8. Send reboot message to all clients**
            StaticJsonDocument<128> rebootMsg;
            rebootMsg["type"] = "rebooting";
            rebootMsg["message"] = "Rebooting, please wait a moment";
            String rebootString;
            serializeJson(rebootMsg, rebootString);
            ws.textAll(rebootString);

            // **9. Delay to ensure the message is sent**
            delay(2000);  // Wait 2 seconds

            // **10. Restart the ESP32**
            ESP.restart();
          } else if (strcmp(type, "setWifi") == 0) {
            // Handling for setting WiFi settings
            String newSsid = doc["ssid"].as<String>();
            String newPassword = doc["password"].as<String>();

            // Password validation: at least 8 characters
            if (newPassword.length() < 8) {
              Serial.println("Password must be at least 8 characters long.");
              // Send error response to the client
              StaticJsonDocument<128> response;
              response["type"] = "wifiSet";
              response["status"] = "error";
              response["message"] = "Password must be at least 8 characters long.";
              String responseString;
              serializeJson(response, responseString);
              client->text(responseString);
              return;
            }

            // Store the new WiFi settings in non-volatile storage
            preferences.putString("ssid", newSsid);
            preferences.putString("password", newPassword);

            Serial.printf("WiFi settings updated - SSID: %s, Passwort: %s\n", newSsid.c_str(), newPassword.c_str());

            // Send confirmation to the client
            StaticJsonDocument<64> response;
            response["type"] = "wifiSet";
            response["status"] = "success";
            String responseString;
            serializeJson(response, responseString);
            client->text(responseString);

            // Send reboot message to all clients
            StaticJsonDocument<128> rebootMsg;
            rebootMsg["type"] = "rebooting";
            rebootMsg["message"] = "Rebooting to apply new WiFi settings...";
            String rebootString;
            serializeJson(rebootMsg, rebootString);
            ws.textAll(rebootString);

            // Delay to ensure the message is sent
            delay(2000);  // Wait 2 seconds

            // Restart the ESP32
            ESP.restart();
          }
        } else {
          Serial.println("Error parsing JSON");
        }
        msg = "";  // Reset message
      }
    } else {
      Serial.println("Binary message received (not supported).");
    }
  }
}