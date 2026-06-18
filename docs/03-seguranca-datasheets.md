# Segurança elétrica e datasheets

## Datasheet antes da montagem

O mesmo nome comercial pode identificar módulos diferentes. “DHT11”, “relé de um canal”, “buzzer” e “PIR” não informam fabricante, circuito do módulo ou pinagem física. Sempre confira o código impresso e o datasheet exato.

Os guias deste repositório usam valores conservadores e módulos comuns. Quando o modelo exato não é conhecido, o valor é marcado como **típico**, não como garantia.

## Regras

- Desligue a alimentação antes de mudar fios.
- GPIO do ESP32: lógica de 3,3 V; não tolera 5 V.
- Use resistor de 220 Ω a 330 Ω em cada canal de LED.
- Use divisor de tensão no ECHO de 5 V do HC-SR04.
- Alimente potenciômetros e divisores analógicos com 3,3 V para limitar a saída ao ADC.
- Servo deve usar fonte externa regulada de 5 V com corrente suficiente e GND comum.
- Não ligue bobina de relé avulso ao GPIO. O exemplo exige módulo com driver integrado e entrada compatível com 3,3 V.
- Não use a saída 3V3 da placa para cargas de alta corrente.

## Fontes principais

- [Datasheet ESP32](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
- [Datasheet ESP32-S3](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)
- [Documentação Arduino-ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [Arduino IoT Cloud](https://docs.arduino.cc/arduino-cloud/)
- [Planos Arduino Cloud](https://cloud.arduino.cc/plans)

Para componentes sem part number confirmado, obtenha o datasheet no site do fabricante ou fornecedor e compare alimentação, pinagem, níveis e corrente antes de seguir o exemplo.
