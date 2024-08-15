#include "Adafruit_VL53L0X.h"               // Bibliothek für Lasersensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();  // Objekt für Lasersensor

#define LED_PIN D5  // LED auf PIN D5

int distanz;  // Variable für die Distanz
int distanzBlitz = 70;  // Variable für die Blitzauslösung