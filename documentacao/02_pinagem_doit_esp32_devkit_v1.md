# DOIT ESP32 DEVKIT V1

## Mapa proposto

| Componente | Terminal | GPIO e tipo |
|---|---|---|
| HC-SR04 | TRIG | GPIO 33 — saída digital |
| HC-SR04 | ECHO | GPIO 34 — entrada digital somente, com divisor |
| DHT11 | DATA | GPIO 23 — entrada/saída digital |
| LDR | Divisor | GPIO 35 — entrada analógica ADC1, somente entrada |
| Potenciômetro | Cursor | GPIO 32 — entrada analógica ADC1 |
| PIR | OUT | GPIO 22 — entrada digital |
| Botão/joystick | SW | GPIO 14 — entrada digital com pull-up |
| Joystick | VRx | GPIO 36 — entrada analógica ADC1, somente entrada |
| Joystick | VRy | GPIO 39 — entrada analógica ADC1, somente entrada |
| LED comum | Ânodo | GPIO 16 — saída digital |
| LED RGB | R/G/B | GPIO 25/26/27 — saídas PWM |
| Buzzer | Sinal | GPIO 18 — saída PWM |
| Servo | Sinal | GPIO 13 — saída de controle |
| Relé | IN | GPIO 19 — saída digital |

## Pinos e limitações

- GPIO 34, 35, 36 e 39 são somente entrada e não têm pull-up/pull-down interno.
- GPIO 6 a 11 são usados pela memória flash e não devem ser conectados.
- GPIO 0, 2, 5, 12 e 15 são strapping/boot; evite cargas que alterem seus níveis durante a inicialização.
- Para leituras analógicas enquanto o Wi-Fi está ativo, prefira **ADC1**. O ADC2 do ESP32 original tem conflito com Wi-Fi.

## Recursos sem fio

- Wi-Fi 2,4 GHz: sim.
- BLE: sim.
- Bluetooth Classic/Serial: sim.
