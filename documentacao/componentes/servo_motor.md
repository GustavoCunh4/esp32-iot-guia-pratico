# Servo motor

O exemplo considera um microservo tipo SG90, mas clones variam muito. Usa **3 fios e 1 GPIO de sinal**:

| Cor típica | Função |
|---|---|
| Marrom/preto | GND |
| Vermelho | 5 V externo |
| Laranja/amarelo | Sinal GPIO |

É necessária fonte externa regulada de 5 V, recomendada a partir de 1 A para testes, e GND comum com o ESP32. Não alimente o servo pelo GPIO nem pelo 3V3.

O teste usa `ESP32Servo` e percorre 0°, 90° e 180°. Se houver ruído, travamento ou aquecimento, desligue; alguns mecanismos não permitem o curso inteiro.
