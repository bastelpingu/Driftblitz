float getCPUTemperature() {
  // ESP32 internal API to read the CPU temperature in Celsius
  return (temperatureRead());  // Temperature directly in Celsius
}

  void displayRAMUsage(uint32_t & freeRAM, float &ramFreePercent) {
    freeRAM = esp_get_free_heap_size() / 1024;     // in kB
    uint32_t totalRAM = ESP.getHeapSize() / 1024;  // in kB
    uint32_t usedRAM = totalRAM - freeRAM;
    ramFreePercent = ((float)freeRAM / (float)totalRAM) * 100.0;

    // Display RAM usage
    Serial.print("Free RAM: ");
    Serial.print(freeRAM);
    Serial.print(" kB (");
    Serial.print(ramFreePercent);
    Serial.println("% free)");
  }


  void ueberwachung() {
    uint64_t currentTime = esp_timer_get_time();
    uint64_t totalTimeDiff = currentTime - lastTotalTime;
    lastTotalTime = currentTime;

    uint64_t idleTimeDiff;

    // Critical section to protect shared variables
    portENTER_CRITICAL(&myMutex);
    idleTimeDiff = idleTimeAccum - lastIdleTimeAccum;
    lastIdleTimeAccum = idleTimeAccum;
    portEXIT_CRITICAL(&myMutex);

    cpuLoad = (1.0 - ((float)idleTimeDiff / (float)totalTimeDiff)) * 100.0;

    // Limit the CPU load between 0% and 100%
    if (cpuLoad < 0.0) cpuLoad = 0.0;
    if (cpuLoad > 100.0) cpuLoad = 100.0;

    Serial.printf("CPU Load Core: %.2f%%\n", cpuLoad);

    // CPU-Temperatur auslesen
    cpuTemp = getCPUTemperature();
    cpuTemp = getCPUTemperature();
    Serial.print(cpuTemp);
    Serial.println(" °C");

    // Display RAM usage
    uint32_t freeRAM = 0;
    float ramFreePercent = 0.0;
    displayRAMUsage(freeRAM, ramFreePercent);

    // Create JSON document for system info
    StaticJsonDocument<256> doc;
    doc["cpuLoad"] = cpuLoad;
    doc["cpuTemp"] = cpuTemp;
    doc["freeRAM"] = freeRAM;
    doc["ramFreePercent"] = ramFreePercent;

    // Send JSON over WebSocket
    String json;
    serializeJson(doc, json);
    ws.textAll(json);
  }