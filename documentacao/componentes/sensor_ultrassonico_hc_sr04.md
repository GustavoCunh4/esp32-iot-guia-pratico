# Sensor ultrassônico HC-SR04

Mede distância pelo tempo entre um pulso ultrassônico transmitido e seu eco.

| Terminal | Função | Ligação |
|---|---|---|
| VCC | Alimentação típica do módulo | 5 V |
| TRIG | Entrada digital do sensor | GPIO de saída digital |
| ECHO | Saída digital de aproximadamente 5 V | GPIO de entrada por divisor |
| GND | Terra | GND |

Usa **4 terminais físicos e 2 GPIOs digitais**. O divisor recomendado é 1 kΩ entre ECHO e GPIO e 2 kΩ entre GPIO e GND, reduzindo 5 V para aproximadamente 3,33 V.

O código envia TRIG por 10 µs, mede ECHO com `pulseIn()` e calcula `distância = duração × 0,0343 / 2`. Timeout evita travamento quando não há eco. Superfícies inclinadas, macias ou muito próximas podem falhar.
