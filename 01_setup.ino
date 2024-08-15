void setup() {
  pinMode(LED_PIN, OUTPUT);  // Setze den Pin, der die LED steuert, auf OUTPUT
  Serial.begin(115200);      // Starte die serielle Kommunikation
  delay(1500);               // Pause für Sensor
  Serial.println("");        // Drucke eine leere Zeile zur besseren Lesbarkeit
  Serial.println("Starting Sensor Test...");

  // Versuche, den VL53L0X-Sensor zu initialisieren
  if (!lox.begin()) {
    Serial.println(F("Error: Failed to initialize VL53L0X sensor."));
    // Endlosschleife, um das Programm anzuhalten
    while (1)
      ;
  } else {
    Serial.println("Success: VL53L0X sensor initialized.");
  }
  // Aktiviere den High-Speed-Modus des VL53L0X-Sensors
  lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_SPEED);
}