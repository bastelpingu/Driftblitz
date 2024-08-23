#include "Adafruit_VL53L0X.h"               // Bibliothek für Lasersensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();  // Objekt für Lasersensor

#define LED_PIN D5  // LED auf PIN D5

int distanz;  // Variable für die Distanz
int distanzBlitz = 70;  // Schwellenwert (in Millimetern) für die Blitzauslösung: Wenn die gemessene Distanz kleiner oder gleich diesem Wert ist, wird die LED ausgelöst
