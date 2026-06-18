# GPIO, digital, analógico e PWM

## O que é GPIO

GPIO significa **General Purpose Input/Output**. É um terminal programável do microcontrolador. Na placa, normalmente aparece apenas o número, por exemplo `18`; no código usamos `GPIO 18`.

Um número impresso não significa automaticamente “analógico”. O programa e as capacidades internas do chip determinam como o GPIO será usado.

| Identificação | O que significa | É GPIO? |
|---|---|---|
| `GPIO 13` ou `13` | Sinal programável | Sim |
| `3V3` | Alimentação regulada de 3,3 V | Não |
| `5V`, `VIN` ou `VBUS` | Alimentação de 5 V, conforme a placa | Não |
| `GND` | Referência elétrica/terra | Não |
| `EN` ou `RST` | Habilitação/reinicialização | Não é de uso geral |

## Tipos usados neste projeto

- **Entrada digital:** lê apenas `LOW` ou `HIGH`. Exemplo: botão e PIR.
- **Saída digital:** envia `LOW` ou `HIGH`. Exemplo: LED e relé.
- **Entrada analógica (ADC):** mede uma tensão entre 0 V e o limite do ADC e converte em número. Exemplo: LDR e potenciômetro.
- **Saída PWM:** alterna rapidamente um sinal digital para simular intensidade média. Exemplo: brilho de LED RGB e buzzer.

O ESP32 não possui uma saída analógica real em todos os pinos. PWM continua sendo um sinal digital.

## Convenções usadas nos códigos

```cpp
const int GPIO_BOTAO_DIGITAL_ENTRADA = 10;
const int GPIO_LDR_ADC_ENTRADA = 18;
const int GPIO_LED_PWM_SAIDA = 4;
```

O nome informa componente, função elétrica e direção. Todos os números são GPIOs, não posições físicas contadas a partir do canto da placa.

## Regras essenciais

1. GPIOs usam lógica de 3,3 V.
2. Não aplique 5 V em um GPIO.
3. `GND` dos módulos e do ESP32 deve ser comum, salvo circuitos isolados projetados para não compartilhar terra.
4. ADC só funciona nos GPIOs com capacidade analógica.
5. Alguns GPIOs participam do boot, USB, memória flash ou PSRAM e devem ser evitados.
6. GPIO não é fonte de potência.
