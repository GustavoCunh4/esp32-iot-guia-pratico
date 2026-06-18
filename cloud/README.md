# Exemplos Arduino IoT Cloud

Leia primeiro [o guia completo](../docs/06-arduino-iot-cloud.md).

Cada pasta contém um projeto-base para Arduino IDE com cinco variáveis, respeitando o limite informado para o plano gratuito em 18/06/2026. A Arduino Cloud pode gerar um `thingProperties.h` diferente; se isso acontecer, use o arquivo gerado pelo serviço e mantenha os mesmos nomes de variáveis/callback.

## Antes de compilar

1. Crie o Device e a Thing na Arduino Cloud.
2. Crie `ledCloud`, `temperaturaCloud`, `luminosidadeCloud`, `potenciometroCloud` e `botaoCloud` com os tipos descritos no guia.
3. Copie `arduino_secrets.example.h` para `arduino_secrets.h`.
4. Preencha Wi-Fi, Device Login Name/ID e Secret Device Key.
5. Instale `ArduinoIoTCloud`, `Arduino_ConnectionHandler`, `DHT sensor library` e `Adafruit Unified Sensor`.

Nunca envie `arduino_secrets.h` ao GitHub.
