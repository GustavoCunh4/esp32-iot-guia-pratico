# LED comum

LED possui ânodo e cátodo e usa **1 GPIO de saída digital**.

```text
GPIO ── resistor 220 a 330 Ω ── ânodo LED | cátodo ── GND
```

A perna longa costuma ser o ânodo; o lado achatado costuma indicar o cátodo. Confirme pelo datasheet. Nunca elimine o resistor.

O teste alterna HIGH e LOW a cada segundo. LEDs de cores diferentes têm quedas de tensão diferentes; o resistor limita a corrente a um valor seguro.
