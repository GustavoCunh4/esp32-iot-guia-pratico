#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(200);
  Serial.println("Buscando redes Wi-Fi 2,4 GHz...");
}

void loop() {
  int quantidade = WiFi.scanNetworks();
  if (quantidade == 0) Serial.println("Nenhuma rede encontrada.");
  for (int i = 0; i < quantidade; i++) {
    Serial.printf("%2d | %-32s | RSSI %4d dBm | canal %2d | %s\n", i + 1,
                  WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i),
                  WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "aberta" : "protegida");
  }
  WiFi.scanDelete();
  Serial.println("Nova busca em 10 segundos.\n");
  delay(10000);
}
