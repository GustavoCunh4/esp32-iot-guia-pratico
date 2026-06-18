# ESP32-S3 configurado como ESP32S3 Dev Module

## Identificação

`ESP32S3 Dev Module` é um perfil genérico da Arduino IDE. Placas com 38 ou 44 pinos, diferentes conversores USB e diferentes quantidades de flash/PSRAM podem usar esse mesmo perfil.

Confira:

- texto gravado no módulo metálico;
- números impressos ao lado dos conectores;
- quantidade de pinos;
- documentação do vendedor;
- se a conexão USB usa USB nativo ou conversor USB/serial.

## Mapa proposto

| Componente | Terminal | GPIO e tipo |
|---|---|---|
| HC-SR04 | TRIG | GPIO 11 — saída digital |
| HC-SR04 | ECHO | GPIO 12 — entrada digital, com divisor |
| DHT11 | DATA | GPIO 13 — entrada/saída digital |
| LDR | Divisor | GPIO 18 — entrada analógica ADC |
| Potenciômetro | Cursor | GPIO 2 — entrada analógica ADC |
| PIR | OUT | GPIO 14 — entrada digital |
| Botão/joystick | SW | GPIO 10 — entrada digital com pull-up |
| Joystick | VRx | GPIO 7 — entrada analógica ADC |
| Joystick | VRy | GPIO 8 — entrada analógica ADC |
| LED comum | Ânodo | GPIO 15 — saída digital |
| LED RGB | R/G/B | GPIO 4/6/5 — saídas PWM |
| Buzzer | Sinal | GPIO 21 — saída PWM |
| Servo | Sinal | GPIO 17 — saída de controle |
| Relé | IN | GPIO 38 — saída digital |

## Pinos evitados

- GPIO 0, 3, 45 e 46: strapping/boot; o comportamento depende da placa.
- GPIO 19 e 20: normalmente usados pelo USB nativo.
- GPIO 26 a 32: associados à flash/PSRAM em muitos módulos.
- GPIO 35 a 37: podem estar ocupados em módulos com flash/PSRAM octal.

Nem todo GPIO existe em todo conector. Se um número da tabela não estiver impresso na sua placa, não escolha um substituto aleatório: consulte o datasheet e atualize o código.

## Recursos sem fio

- Wi-Fi 2,4 GHz: sim.
- Bluetooth Low Energy (BLE): sim.
- Bluetooth Classic/Serial: não.
