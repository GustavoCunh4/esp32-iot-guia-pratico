# Joystick analógico

O módulo comum possui **5 terminais e usa 3 GPIOs**:

| Terminal | Função | Tipo |
|---|---|---|
| VCC | Alimentação | 3V3 |
| GND | Terra | GND |
| VRx | Eixo X | Entrada analógica ADC |
| VRy | Eixo Y | Entrada analógica ADC |
| SW | Botão | Entrada digital com pull-up |

Alimente em 3,3 V para manter VRx/VRy seguros. O centro costuma ficar próximo de metade da escala, mas deve ser calibrado. O teste mostra X, Y, direção e botão; uma zona morta reduz falsos movimentos no centro.
