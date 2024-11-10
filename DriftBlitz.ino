#include <WiFi.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include <Arduino.h>
#include "esp_freertos_hooks.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <SimpleTimer.h>
#include <ArduinoJson.h>
#include <Preferences.h>
#include <Wire.h>
#include <VL53L0X.h>

// Variables for pins
int LED_PIN = 20;  // Default value for LED_PIN
int SCL_PIN = 22;  // Default value for SCL_PIN
int SDA_PIN = 21;  // Default value for SDA_PIN

// WiFi configuration
String ssid;
String password;

// Time tracking variable for WebSocket transmissions
unsigned long previousWebSocketMillis = 0;
const unsigned long webSocketInterval = 200;  // 200 ms

SimpleTimer systeminfos;

float distanzLED = 10;


unsigned long hotspotStartTime = 0;  // Time when the hotspot started
bool hotspotDeactivated = false;     // Flag to ensure the hotspot is deactivated only once


// Create an Async Web Server on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

int lastProgress = 0;                        // Last progress value for firmware upload
unsigned long lastWebSocketMessageTime = 0;  // Last timestamp for WebSocket message
unsigned long messageInterval = 500;         // Time interval between WebSocket messages (500 ms)
String monitorOutput = "";

// Monitoring
volatile uint64_t idleTimeAccum = 0;
uint64_t lastIdleTimeAccum = 0;
uint64_t lastTotalTime = 0;
float cpuTemp = 0;
float cpuLoad = 0;
portMUX_TYPE myMutex = portMUX_INITIALIZER_UNLOCKED;

// Preferences object for non-volatile storage
Preferences preferences;

// VL53L0X Sensor
VL53L0X sensor;

// Variables for sensor measurements
uint16_t distance;
String sensorStatus;
bool sensorInitialized = false;  // New flag for sensor status

// Idle-Hook-Funktion für Core 0
bool myIdleHook(void) {
  static uint64_t lastIdleTime = 0;
  uint64_t currentTime = esp_timer_get_time();

  if (lastIdleTime != 0) {
    uint64_t idleDiff = currentTime - lastIdleTime;

    // Critical section to protect shared variables
    portENTER_CRITICAL(&myMutex);
    idleTimeAccum += idleDiff;
    portEXIT_CRITICAL(&myMutex);
  }

  lastIdleTime = currentTime;
  return true;
}