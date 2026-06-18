#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

const int GPIO_LED_DIGITAL_SAIDA = 15;
const char *UUID_SERVICO = "7b9a0001-6c3d-4b4f-9c98-91a34b25c001";
const char *UUID_LED = "7b9a0002-6c3d-4b4f-9c98-91a34b25c001";

class LedCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *caracteristica) override {
    String valor = caracteristica->getValue().c_str();
    bool ligado = valor == "1" || valor.equalsIgnoreCase("ON");
    digitalWrite(GPIO_LED_DIGITAL_SAIDA, ligado ? HIGH : LOW);
    caracteristica->setValue(ligado ? "1" : "0");
    Serial.println(ligado ? "BLE: LED ligado" : "BLE: LED desligado");
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
  BLEDevice::init("ESP32S3-BLE-LED");
  BLEServer *servidor = BLEDevice::createServer();
  BLEService *servico = servidor->createService(UUID_SERVICO);
  BLECharacteristic *led = servico->createCharacteristic(
      UUID_LED, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  led->setValue("0");
  led->setCallbacks(new LedCallbacks());
  servico->start();
  BLEAdvertising *anuncio = BLEDevice::getAdvertising();
  anuncio->addServiceUUID(UUID_SERVICO);
  anuncio->start();
  Serial.println("No nRF Connect, procure ESP32S3-BLE-LED e escreva 1 ou 0.");
}

void loop() { delay(1000); }
