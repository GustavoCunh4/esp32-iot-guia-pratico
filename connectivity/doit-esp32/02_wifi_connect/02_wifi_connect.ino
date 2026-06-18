#include <WiFi.h>
#include "arduino_secrets.h"

unsigned long ultimaTentativa = 0;

void conectarWiFi() {
  Serial.printf("Conectando a %s", SECRET_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  unsigned long inicio = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - inicio < 15000) {
    Serial.print('.');
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED)
    Serial.printf("\nConectado | IP: %s | MAC: %s | RSSI: %d dBm\n",
                  WiFi.localIP().toString().c_str(), WiFi.macAddress().c_str(), WiFi.RSSI());
  else Serial.println("\nTimeout. Nova tentativa em 10 s.");
}

void setup() { Serial.begin(115200); conectarWiFi(); }

void loop() {
  if (WiFi.status() != WL_CONNECTED && millis() - ultimaTentativa >= 10000) {
    ultimaTentativa = millis();
    WiFi.disconnect();
    conectarWiFi();
  }
  delay(100);
}
