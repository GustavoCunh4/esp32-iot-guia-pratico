# Buzzer

“Buzzer” pode significar dispositivos diferentes:

- ativo: emite tom ao receber nível DC;
- passivo/piezo: precisa de sinal periódico e permite diferentes frequências;
- módulo de 3 pinos: inclui circuito adicional.

O teste considera buzzer passivo/piezo pequeno e usa **1 GPIO PWM** com `tone()`. Para buzzer ativo, use apenas liga/desliga e confirme corrente/polaridade.

Não conecte buzzer eletromagnético de corrente desconhecida diretamente. Consulte o datasheet; se a corrente superar a capacidade segura do GPIO, use driver apropriado.
