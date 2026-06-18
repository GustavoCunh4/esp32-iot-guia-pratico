#include <WiFi.h>
#include <WebServer.h>

// Preencha aqui. Nao publique o arquivo depois de colocar uma senha real.
const char *NOME_REDE_WIFI = "NOME_DA_REDE_2G4";
const char *SENHA_REDE_WIFI = "SENHA_DA_REDE";
const int GPIO_LED_DIGITAL_SAIDA = 16;
WebServer servidor(80);
bool ledLigado = false;

void aplicarLed() { digitalWrite(GPIO_LED_DIGITAL_SAIDA, ledLigado ? HIGH : LOW); }

String pagina() {
  return String("<!doctype html><meta name='viewport' content='width=device-width'>") +
         "<h1>DOIT ESP32 DEVKIT V1</h1><p>LED: <b>" + (ledLigado ? "LIGADO" : "DESLIGADO") +
         "</b></p><p><a href='/ligar'><button>Ligar</button></a> "
         "<a href='/desligar'><button>Desligar</button></a></p>";
}

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
  aplicarLed();
  WiFi.begin(NOME_REDE_WIFI, SENHA_REDE_WIFI);
  while (WiFi.status() != WL_CONNECTED) { Serial.print('.'); delay(500); }
  servidor.on("/", []() { servidor.send(200, "text/html; charset=utf-8", pagina()); });
  servidor.on("/ligar", []() { ledLigado = true; aplicarLed(); servidor.sendHeader("Location", "/"); servidor.send(303); });
  servidor.on("/desligar", []() { ledLigado = false; aplicarLed(); servidor.sendHeader("Location", "/"); servidor.send(303); });
  servidor.onNotFound([]() { servidor.send(404, "text/plain", "Rota inexistente"); });
  servidor.begin();
  Serial.printf("Abra http://%s/\n", WiFi.localIP().toString().c_str());
}

void loop() { servidor.handleClient(); }
