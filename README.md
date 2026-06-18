# Guia prático de IoT com ESP32 e ESP32-S3

Repositório didático em português para estudar sensores, atuadores, Wi-Fi, Bluetooth e Arduino IoT Cloud usando duas placas diferentes:

- **DOIT ESP32 DEVKIT V1**: ESP32 original, com Wi-Fi, BLE e Bluetooth Classic.
- **ESP32-S3 Dev Module**: perfil genérico da Arduino IDE para placas ESP32-S3, com Wi-Fi e BLE, mas sem Bluetooth Classic.

> **Atenção:** `ESP32S3 Dev Module` é o nome do perfil de compilação, não identifica sozinho o fabricante nem o layout físico da placa. Antes de ligar qualquer fio, confirme se o número GPIO está impresso na sua placa.

## O que existe neste repositório

- [Conceitos de GPIO, digital, analógico e PWM](documentacao/00_conceitos_gpio_digital_analogico_pwm.md)
- [Pinagem proposta para ESP32-S3](documentacao/01_pinagem_esp32_s3.md)
- [Pinagem proposta para DOIT ESP32 DEVKIT V1](documentacao/02_pinagem_doit_esp32_devkit_v1.md)
- [Segurança elétrica, datasheets e limitações](documentacao/03_seguranca_eletrica_e_datasheets.md)
- [Wi-Fi](documentacao/04_conectar_wifi.md)
- [Bluetooth e BLE](documentacao/05_conectar_bluetooth_e_ble.md)
- [Arduino IoT Cloud pelo Arduino IDE](documentacao/06_usar_arduino_iot_cloud.md)
- [Solução de problemas](documentacao/07_solucao_de_problemas.md)
- [Guias individuais dos componentes](documentacao/componentes/README.md)
- `testes-componentes/esp32-s3`: testes individuais para ESP32-S3.
- `testes-componentes/doit-esp32-devkit-v1`: testes individuais para DOIT ESP32.
- `conectividade`: Wi-Fi, servidor web, BLE e Bluetooth Classic.
- `arduino-iot-cloud`: exemplos Cloud com arquivos separados e em arquivo único.

Os nomes de pastas e sketches estão em português e descrevem a finalidade do teste. Os caminhos não usam acentos nem espaços para evitar incompatibilidades entre Arduino IDE, sistemas operacionais e ferramentas de linha de comando.

## Arquivo único ou arquivos separados

Os testes de componentes, procura de Wi-Fi e Bluetooth já usam somente um `.ino`.

Exemplos que precisam de credenciais oferecem duas versões:

- **`arquivo_unico`**: configuração e código no mesmo `.ino`, mais próximo do uso básico na Arduino IDE;
- **`segredos_separados` ou `arquivos_separados`**: mantém senhas e propriedades em `.h`, opção recomendada para GitHub.

As alternativas ficam em pastas diferentes porque a Arduino IDE compila todos os `.ino` encontrados na mesma pasta.

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

1. Leia primeiro o guia do componente em `documentacao/componentes`.
2. Escolha a pasta da sua placa.
3. Abra o arquivo `.ino` dentro da pasta do teste. O arquivo principal tem o mesmo nome da pasta, como exigido pela Arduino IDE.
4. Confira todos os GPIOs e tensões.
5. Faça a montagem com a placa desligada.
6. Compile, envie e abra o Monitor Serial em **115200 baud**.

## Regra de segurança

Os GPIOs do ESP32 trabalham com lógica de **3,3 V** e não são tolerantes a 5 V. Nunca ligue motor, solenoide, servo, relé eletromecânico avulso ou outra carga de potência diretamente a um GPIO.

## Licença

[MIT](LICENSE)
