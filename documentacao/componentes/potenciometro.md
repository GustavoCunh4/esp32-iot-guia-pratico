# Potenciômetro

Um potenciômetro possui **3 terminais e usa 1 GPIO ADC**:

- uma extremidade em 3V3;
- outra em GND;
- terminal central, chamado cursor, no GPIO ADC.

Não alimente com 5 V, pois o cursor poderia aplicar 5 V ao ESP32. O teste calcula média, valor bruto de 0 a 4095 e percentual. Inverter as extremidades apenas inverte o sentido de crescimento.

Valores entre 5 kΩ e 20 kΩ são comuns para esse uso; confirme o part number e não use potenciômetros de potência como se fossem equivalentes.
