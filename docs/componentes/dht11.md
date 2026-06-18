# DHT11

Sensor digital de temperatura e umidade, lento e de precisão limitada.

| Versão | Terminais |
|---|---|
| Sensor avulso | VCC, DATA, NC e GND; use pull-up típico de 10 kΩ em DATA |
| Módulo | Geralmente VCC, DATA e GND; costuma incluir pull-up |

Usa **1 GPIO digital bidirecional**. Alimente em 3,3 V neste projeto. O teste lê a cada 2 segundos, respeitando a baixa taxa de amostragem. `NaN` indica falha, pinagem errada ou biblioteca ausente.

Bibliotecas externas: `DHT sensor library` e `Adafruit Unified Sensor`.
