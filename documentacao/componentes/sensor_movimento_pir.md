# Sensor de movimento PIR

O exemplo considera um módulo comum HC-SR501. Confirme o modelo, pois PIR avulso e outros módulos têm circuitos diferentes.

| Terminal | Ligação típica |
|---|---|
| VCC | 5 V no HC-SR501 |
| OUT | GPIO de entrada digital |
| GND | GND |

Usa **3 terminais e 1 GPIO digital**. O OUT do HC-SR501 é tipicamente compatível com lógica de 3,3 V, mas confirme seu módulo.

Após energizar, aguarde aproximadamente 30 a 60 segundos para estabilização. Ajustes físicos controlam sensibilidade e tempo. O código detecta mudanças e informa início/fim de movimento.
