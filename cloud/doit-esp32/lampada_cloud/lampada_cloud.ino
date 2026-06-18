#include <DHT.h>
#include "thingProperties.h"

const int GPIO_LED_DIGITAL_SAIDA = 16;
const int GPIO_DHT_DIGITAL_DADOS = 23;
const int GPIO_LDR_ADC1_ENTRADA = 35;
const int GPIO_POTENCIOMETRO_ADC1_ENTRADA = 32;
const int GPIO_BOTAO_DIGITAL_ENTRADA = 14;
DHT dht(GPIO_DHT_DIGITAL_DADOS, DHT11);
unsigned long ultimaLeitura = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
  pinMode(GPIO_BOTAO_DIGITAL_ENTRADA, INPUT_PULLUP);
  analogReadResolution(12);
  dht.begin();
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  if (millis() - ultimaLeitura >= 2000) {
    ultimaLeitura = millis();
    float temperatura = dht.readTemperature();
    if (!isnan(temperatura)) temperaturaCloud = temperatura;
    luminosidadeCloud = analogRead(GPIO_LDR_ADC1_ENTRADA);
    potenciometroCloud = analogRead(GPIO_POTENCIOMETRO_ADC1_ENTRADA);
    botaoCloud = digitalRead(GPIO_BOTAO_DIGITAL_ENTRADA) == LOW;
    Serial.printf("T:%.1f C | LDR:%d | POT:%d | Botao:%s | LED:%s\n",
                  temperaturaCloud, luminosidadeCloud, potenciometroCloud,
                  botaoCloud ? "ON" : "OFF", ledCloud ? "ON" : "OFF");
  }
}

void onLedCloudChange() {
  digitalWrite(GPIO_LED_DIGITAL_SAIDA, ledCloud ? HIGH : LOW);
}
