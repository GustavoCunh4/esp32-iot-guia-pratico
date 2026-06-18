#include <DHT.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// Credenciais no proprio sketch. Nao publique depois de inserir valores reais.
const char DEVICE_LOGIN_NAME[] = "DEVICE_LOGIN_NAME_OU_DEVICE_ID";
const char SSID[] = "NOME_DA_REDE_2G4";
const char PASS[] = "SENHA_DA_REDE";
const char DEVICE_KEY[] = "SECRET_DEVICE_KEY";

const int GPIO_LED_DIGITAL_SAIDA = 15;
const int GPIO_DHT_DIGITAL_DADOS = 13;
const int GPIO_LDR_ADC_ENTRADA = 18;
const int GPIO_POTENCIOMETRO_ADC_ENTRADA = 2;
const int GPIO_BOTAO_DIGITAL_ENTRADA = 10;

bool ledCloud;
float temperaturaCloud;
int luminosidadeCloud;
int potenciometroCloud;
bool botaoCloud;
DHT dht(GPIO_DHT_DIGITAL_DADOS, DHT11);
WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
unsigned long ultimaLeitura = 0;

void onLedCloudChange();

void configurarPropriedadesCloud() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(ledCloud, READWRITE, ON_CHANGE, onLedCloudChange);
  ArduinoCloud.addProperty(temperaturaCloud, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(luminosidadeCloud, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(potenciometroCloud, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(botaoCloud, READ, ON_CHANGE, NULL);
}

void setup() {
  Serial.begin(115200);
  delay(1500);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
  pinMode(GPIO_BOTAO_DIGITAL_ENTRADA, INPUT_PULLUP);
  analogReadResolution(12);
  dht.begin();
  configurarPropriedadesCloud();
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
    luminosidadeCloud = analogRead(GPIO_LDR_ADC_ENTRADA);
    potenciometroCloud = analogRead(GPIO_POTENCIOMETRO_ADC_ENTRADA);
    botaoCloud = digitalRead(GPIO_BOTAO_DIGITAL_ENTRADA) == LOW;
    Serial.printf("T:%.1f C | LDR:%d | POT:%d | Botao:%s | LED:%s\n",
                  temperaturaCloud, luminosidadeCloud, potenciometroCloud,
                  botaoCloud ? "ON" : "OFF", ledCloud ? "ON" : "OFF");
  }
}

void onLedCloudChange() {
  digitalWrite(GPIO_LED_DIGITAL_SAIDA, ledCloud ? HIGH : LOW);
}
