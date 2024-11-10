void loop() {
  systeminfos.run();

  if (sensorInitialized) {
    // Read sensor data
    distance = sensor.readRangeContinuousMillimeters();

    // Check if a timeout occurred
    if (sensor.timeoutOccurred()) {
      sensorStatus = "Nicht OK";
      sensorInitialized = false;  // Sensor is no longer initialized
      Serial.println("Sensor timeout occurred.");
    } else {
      sensorStatus = "OK";
    }
  } else {
    // Attempt to reinitialize the sensor
    sensor.setTimeout(500);
    if (sensor.init()) {
      sensorInitialized = true;
      sensorStatus = "OK";
      sensor.setMeasurementTimingBudget(50000);
      sensor.startContinuous();
      Serial.println("Sensor successfully reinitialized.");
    } else {
      sensorStatus = "Nicht OK";
      Serial.println("Sensor could not be reinitialized.");
    }
    delay(1000);  // Wait one second before the next attempt
  }

  // Output the distance and sensor status
  Serial.print("Sensor status: ");
  Serial.println(sensorStatus);
  if (sensorInitialized) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }

  int distanzLED_mm = distanzLED * 10;

  // Get the current time
  unsigned long currentMillis = millis();

  // Check if the interval has passed
  if (currentMillis - previousWebSocketMillis >= webSocketInterval) {
    previousWebSocketMillis = currentMillis;

    // Create JSON document for sensor data
    StaticJsonDocument<128> sensorDoc;
    sensorDoc["sensorStatus"] = sensorStatus;

    if (sensorInitialized) {
      sensorDoc["distance"] = distance;
    } else {
      sensorDoc["distance"] = nullptr;  // No valid value
    }

    // Send JSON over WebSocket
    String sensorJson;
    serializeJson(sensorDoc, sensorJson);
    ws.textAll(sensorJson);

    if (distanzLED_mm > distance && distance > 5) {
      // Send "LED ON" over WebSocket
      ws.textAll("{\"message\":\"LED AN\"}");
    }
  }

  // Only proceed if the sensor is initialized
    if (sensorInitialized) {
    // Convert `distanzLED` from cm to mm

    if (distanzLED_mm > distance && distance > 5) {
      Serial.println("LED ON");
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(70);
    }
  }


  // Check if 5 minutes (300,000 ms) have passed and the hotspot is still active
    if (!hotspotDeactivated && (millis() - hotspotStartTime >= 300000)) {  // 300.000 ms = 5 mins
    WiFi.softAPdisconnect(true);                                        // Deactivate the hotspot
    Serial.println("Hotspot deactivated after 5 minutes.");
    hotspotDeactivated = true;  // Set flag to prevent multiple deactivations
  }
}