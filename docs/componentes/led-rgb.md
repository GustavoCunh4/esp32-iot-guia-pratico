# LED RGB

LED RGB possui **4 terminais e usa 3 GPIOs PWM**, um para cada cor. Existem dois tipos:

- cátodo comum: comum no GND; 255 representa brilho máximo;
- ânodo comum: comum em 3V3; valores PWM precisam ser invertidos.

Cada canal exige seu próprio resistor de 220 a 330 Ω. Não use um único resistor no terminal comum.

O teste define `LED_RGB_ANODO_COMUM` e percorre vermelho, verde, azul, misturas e branco. Se as cores não corresponderem, identifique as pernas no datasheet em vez de trocar números aleatoriamente.
