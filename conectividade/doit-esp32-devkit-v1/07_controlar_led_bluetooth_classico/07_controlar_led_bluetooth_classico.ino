#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_SPP_ENABLED)
#error "Bluetooth Classic SPP nao esta disponivel nesta placa. Use DOIT ESP32, nao ESP32-S3."
#endif

const int GPIO_LED_DIGITAL_SAIDA = 16;
BluetoothSerial serialBluetooth;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
  serialBluetooth.begin("ESP32-Serial");
  Serial.println("Pareie com ESP32-Serial e envie 1, 0 ou ?.");
}

void loop() {
  if (serialBluetooth.available()) {
    char comando = serialBluetooth.read();
    if (comando == '1') {
      digitalWrite(GPIO_LED_DIGITAL_SAIDA, HIGH);
      serialBluetooth.println("LED ligado");
    } else if (comando == '0') {
      digitalWrite(GPIO_LED_DIGITAL_SAIDA, LOW);
      serialBluetooth.println("LED desligado");
    } else if (comando == '?') {
      serialBluetooth.println(digitalRead(GPIO_LED_DIGITAL_SAIDA) ? "LED ligado" : "LED desligado");
    }
  }
}
