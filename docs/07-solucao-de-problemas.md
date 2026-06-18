# Solução de problemas

## A porta não aparece

- Troque o cabo por um cabo USB de dados.
- Instale o driver CP210x ou CH340 se a placa utilizar esse conversor.
- Tente outra porta USB.
- No ESP32-S3, mantenha BOOT pressionado, toque RESET e solte BOOT para entrar no modo de gravação quando necessário.

## O upload falha

- Confirme placa e porta.
- Feche outros monitores seriais.
- Remova temporariamente circuitos dos pinos de boot.
- Reduza Upload Speed.

## Leituras analógicas oscilam

- Use fios curtos e GND comum.
- Não deixe entrada flutuando.
- Faça média de várias amostras.
- No DOIT com Wi-Fi, use ADC1.

## A placa reinicia

- Provável queda de alimentação causada por servo, relé ou USB insuficiente.
- Alimente cargas separadamente e una os GNDs quando apropriado.
- Verifique curto-circuito e polaridade.

## Caracteres ilegíveis

O baud rate do Monitor Serial deve coincidir com `Serial.begin(115200)`.
