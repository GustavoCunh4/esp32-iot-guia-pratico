# Guia prático de IoT com ESP32 e ESP32-S3

Repositório didático em português para estudar sensores, atuadores, Wi-Fi, Bluetooth e Arduino IoT Cloud usando duas placas diferentes:

- **DOIT ESP32 DEVKIT V1**: ESP32 original, com Wi-Fi, BLE e Bluetooth Classic.
- **ESP32-S3 Dev Module**: perfil genérico da Arduino IDE para placas ESP32-S3, com Wi-Fi e BLE, mas sem Bluetooth Classic.

> **Atenção:** `ESP32S3 Dev Module` é o nome do perfil de compilação, não identifica sozinho o fabricante nem o layout físico da placa. Antes de ligar qualquer fio, confirme se o número GPIO está impresso na sua placa.

## O que existe neste repositório

- [Conceitos de GPIO, digital, analógico e PWM](docs/00-conceitos-gpio.md)
- [Pinagem proposta para ESP32-S3](docs/01-esp32-s3.md)
- [Pinagem proposta para DOIT ESP32 DEVKIT V1](docs/02-doit-esp32.md)
- [Segurança elétrica, datasheets e limitações](docs/03-seguranca-datasheets.md)
- [Wi-Fi](docs/04-wifi.md)
- [Bluetooth e BLE](docs/05-bluetooth.md)
- [Arduino IoT Cloud pelo Arduino IDE](docs/06-arduino-iot-cloud.md)
- [Solução de problemas](docs/07-solucao-de-problemas.md)
- [Guias individuais dos componentes](docs/componentes/README.md)
- `examples/esp32s3`: testes individuais para ESP32-S3.
- `examples/doit-esp32`: testes individuais para DOIT ESP32.
- `connectivity`: exemplos de Wi-Fi, BLE e Bluetooth Classic.
- `cloud`: exemplos-base para Arduino IoT Cloud.

## Componentes cobertos

HC-SR04, DHT11, LDR, PIR, potenciômetro, botão, joystick, LED comum, LED RGB, buzzer, servo e módulo relé de um canal sem carga.

Não fazem parte do escopo: YF-S201, NFC NTAG213, MOSFET, fonte de 12 V, diodo de proteção, motor DC e válvula solenoide.

## Preparação do Arduino IDE

1. Instale o [Arduino IDE 2](https://www.arduino.cc/en/software).
2. Abra **Arquivo > Preferências**.
3. Em “URLs adicionais para Gerenciadores de Placas”, adicione:
   `https://espressif.github.io/arduino-esp32/package_esp32_index.json`
4. Abra **Ferramentas > Placa > Gerenciador de Placas**.
5. Instale **esp32 by Espressif Systems**.
6. Para o ESP32-S3, selecione **ESP32S3 Dev Module**.
7. Para o DOIT, selecione **DOIT ESP32 DEVKIT V1**.
8. Conecte a placa com um **cabo USB de dados** e selecione a porta correta.

Bibliotecas externas usadas:

- `DHT sensor library` da Adafruit e `Adafruit Unified Sensor` para o DHT11.
- `ESP32Servo` para o servo.
- `ArduinoIoTCloud` e `Arduino_ConnectionHandler` para Arduino IoT Cloud.

Wi-Fi, `WebServer`, BLE e `BluetoothSerial` fazem parte do pacote de placas ESP32. `BluetoothSerial` só funciona no ESP32 original.

## Como executar um teste

1. Leia primeiro o guia do componente em `docs/componentes`.
2. Escolha a pasta da sua placa.
3. Abra o arquivo `.ino` dentro da pasta do teste.
4. Confira todos os GPIOs e tensões.
5. Faça a montagem com a placa desligada.
6. Compile, envie e abra o Monitor Serial em **115200 baud**.

## Regra de segurança

Os GPIOs do ESP32 trabalham com lógica de **3,3 V** e não são tolerantes a 5 V. Nunca ligue motor, solenoide, servo, relé eletromecânico avulso ou outra carga de potência diretamente a um GPIO.

## Licença

[MIT](LICENSE)
