void loop() {
  VL53L0X_RangingMeasurementData_t measure;  // Struktur zur Speicherung der Messdaten

  // Führe eine Messung mit dem Sensor durch und speichere die Ergebnisse in 'measure'
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);  // Übergebe 'true', um Debug-Daten auszugeben

  if (measure.RangeStatus != 4) {  // Gültige Messung
    distanz = measure.RangeMilliMeter;
    Serial.print("distance: ");
    Serial.print(distanz);
    Serial.println(" mm");
  } else {  // Ungültige Messung
    distanz = 1000;
    Serial.println("“Distance not measurable”");
  }

  // Überprüfe die gemessene Distanz und steuere die LED entsprechend
  if (distanz < distanzBlitz && distanz > 1) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }

  // Minimale Wartezeit, bevor die nächste Messung durchgeführt wird
  delay(20);
}