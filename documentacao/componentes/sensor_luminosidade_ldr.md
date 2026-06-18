# Sensor de luminosidade LDR

LDR é um resistor dependente de luz, não um sensor com saída pronta. O valor varia também com modelo, temperatura e tolerância.

Monte o divisor:

```text
3V3 ── LDR ── ponto ADC ── resistor 10 kΩ ── GND
```

Usa **2 terminais físicos e 1 GPIO de entrada analógica (ADC)**. Com essa orientação, mais luz normalmente aumenta a leitura. Alimentar o divisor em 3,3 V impede tensão excessiva no ADC.

O exemplo apresenta leitura bruta de 0 a 4095, média e percentual relativo. Esse percentual não representa lux; para lux seria necessário conhecer e calibrar o modelo exato, como GL5528.
