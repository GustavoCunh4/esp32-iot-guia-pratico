#include <DHT.h>

const int GPIO_DHT_DIGITAL_DADOS = 13;
const int TIPO_DHT = DHT11;
DHT dht(GPIO_DHT_DIGITAL_DADOS, TIPO_DHT);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT11 iniciado. Leituras a cada 2 segundos.");
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha no DHT11: confira pino, alimentacao e pull-up.");
  } else {
    Serial.printf("Temperatura: %.1f C | Umidade: %.1f %%\n", temperatura, umidade);
  }
  delay(2000);
}
