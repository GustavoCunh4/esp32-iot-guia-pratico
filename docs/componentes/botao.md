# Botão

Botão comum tem 2 terminais elétricos; modelos tácteis de 4 pernas têm dois pares internamente conectados.

```text
GPIO configurado como INPUT_PULLUP ── botão ── GND
```

Usa **1 GPIO de entrada digital** e não requer resistor externo porque o pull-up interno mantém o estado HIGH. Pressionado produz LOW.

O teste aplica debounce de 40 ms e informa somente mudanças confirmadas. Se o botão tátil parecer sempre pressionado, provavelmente os fios foram colocados no mesmo par interno.
