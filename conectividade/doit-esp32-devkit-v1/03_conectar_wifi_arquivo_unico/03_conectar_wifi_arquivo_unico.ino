#include <WiFi.h>

// Preencha aqui. Nao publique o arquivo depois de colocar uma senha real.
const char *NOME_REDE_WIFI = "NOME_DA_REDE_2G4";
const char *SENHA_REDE_WIFI = "SENHA_DA_REDE";
unsigned long ultimaTentativa = 0;

void conectarWiFi() {
  Serial.printf("Conectando a %s", NOME_REDE_WIFI);
  WiFi.mode(WIFI_STA);
  WiFi.begin(NOME_REDE_WIFI, SENHA_REDE_WIFI);
  unsigned long inicio = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - inicio < 15000) {
    Serial.print('.');
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("\nConectado | IP: %s | MAC: %s | RSSI: %d dBm\n",
                  WiFi.localIP().toString().c_str(), WiFi.macAddress().c_str(), WiFi.RSSI());
  } else {
    Serial.println("\nTempo esgotado. Nova tentativa em 10 segundos.");
  }
}

void setup() {
  Serial.begin(115200);
  conectarWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED && millis() - ultimaTentativa >= 10000) {
    ultimaTentativa = millis();
    WiFi.disconnect();
    conectarWiFi();
  }
  delay(100);
}
