void setup() {
  Serial.begin(115200);

  hotspotStartTime = millis();

  // Initialize preferences
  preferences.begin("my-app", false);                    // "my-app" is the namespace
  distanzLED = preferences.getFloat("distanzLED", 0.0);  // Load the stored value

  // Load saved pin values
  LED_PIN = preferences.getInt("LED_PIN", 20);
  SCL_PIN = preferences.getInt("SCL_PIN", 22);
  SDA_PIN = preferences.getInt("SDA_PIN", 21);

  // Load saved SSID and password or use default values
  ssid = preferences.getString("ssid", "DriftBlitz1");
  password = preferences.getString("password", "12345678");

  // Initialize pins
  pinMode(LED_PIN, OUTPUT);  // Set the pin that controls the LED to OUTPUT
  digitalWrite(LED_PIN, LOW);

  delay(1500);  // Pause for Sensor

  // Initialize Wire
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize sensor
  sensor.setTimeout(500);
  if (sensor.init()) {
    sensorInitialized = true;
    sensorStatus = "OK";
    // Set the timing budget to 50 ms (faster measurements)
    sensor.setMeasurementTimingBudget(50000);
    sensor.startContinuous();
  } else {
    Serial.println("Sensor not found. Please check the wiring.");
    sensorStatus = "Nicht OK";
    sensorInitialized = false;
  }

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS-error");
    return;
  }

  // Set locale to "C" to avoid issues with decimal points
  setlocale(LC_ALL, "C");

  // Start WiFi with a fixed mDNS hostname "driftblitz"
  WiFi.softAP(ssid.c_str(), password.c_str());
  Serial.println("Hotspot gestartet");

  // Set mDNS hostname to "driftblitz"
  if (!MDNS.begin("driftblitz")) {
    Serial.println("Fehler bei started");
  }

  // Register the idle hook only for Core 0
  esp_register_freertos_idle_hook_for_cpu(myIdleHook, 0);
  lastTotalTime = esp_timer_get_time();

  // Register WebSocket event
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  // Define routes with language support
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    // Default language is English
    String lang = "en";

    // Check the "Accept-Language" header
    if (request->hasHeader("Accept-Language")) {
      const AsyncWebHeader *header = request->getHeader("Accept-Language");
      String languages = header->value();

      // Look for German first
      if (languages.indexOf("de") >= 0) {
        lang = "de";
      }
      // If German is not found, check for English
      else if (languages.indexOf("en") >= 0) {
        lang = "en";
      }
    }

    if (lang == "en") {
      request->send_P(200, "text/html", index_en_html);
    } else {
      request->send_P(200, "text/html", index_de_html);
    }
  });


  // Serve CSS (language-independent)
    server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/css", styles_css);
  });

  // Serve JavaScript based on language
    server.on("/scripts_de.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "application/javascript", scripts_de_js);
  });

  server.on("/scripts_en.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "application/javascript", scripts_en_js);
  });

  server.on("/upload", HTTP_POST, handleUpdate, handleUpdateUpload);

  server.begin();
  Serial.println("HTTP-Server started");

  systeminfos.setInterval(1000, ueberwachung);  // Set monitoring every second
}