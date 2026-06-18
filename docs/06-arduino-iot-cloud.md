# Arduino IoT Cloud usando Arduino IDE

## Dependências externas

- conta em [Arduino Cloud](https://app.arduino.cc/);
- internet e rede Wi-Fi 2,4 GHz;
- navegador;
- Arduino IDE local;
- bibliotecas `ArduinoIoTCloud` e `Arduino_ConnectionHandler`;
- Device ID e Secret Key criados ao cadastrar cada placa.

O Arduino Create Agent é necessário para upload direto pelo navegador/Cloud Editor. Para compilar e enviar pelo Arduino IDE local, use o driver USB da placa e as bibliotecas locais.

## Fluxo completo

1. Em Arduino Cloud, abra **Devices** e adicione um dispositivo compatível de terceiros.
2. Selecione ESP32 e registre o Device ID e a Secret Key. A chave pode ser mostrada apenas uma vez.
3. Crie uma **Thing** e associe o dispositivo.
4. Crie até cinco variáveis no exemplo deste repositório:
   - `ledCloud`: Boolean, Read & Write, On change;
   - `temperaturaCloud`: Floating Point, Read Only, periodicamente;
   - `luminosidadeCloud`: Integer, Read Only, periodicamente;
   - `potenciometroCloud`: Integer, Read Only, periodicamente;
   - `botaoCloud`: Boolean, Read Only, On change.
5. Crie widgets no Dashboard e associe cada variável.
6. Abra o sketch gerado pela Thing ou baixe seus arquivos.
7. No Arduino IDE, instale as bibliotecas, mantenha `thingProperties.h` junto do `.ino` e crie `arduino_secrets.h` a partir do exemplo.
8. Selecione a placa e a porta, envie e abra o Monitor Serial em 115200 baud.

## Estrutura do programa

`initProperties()` registra variáveis, permissões e callbacks. `ArduinoCloud.begin(...)` abre a conexão. `ArduinoCloud.update()` deve rodar frequentemente dentro de `loop()`; bloqueios longos impedem o funcionamento da nuvem.

## Limites do plano

Consulte sempre a [página de planos](https://cloud.arduino.cc/plans). Em **18 de junho de 2026**, o plano gratuito informava:

- 2 Things;
- 5 variáveis por Thing;
- retenção de dados por 1 dia;
- 25 compilações por dia no Cloud Editor.

Compilar no Arduino IDE local não consome a cota de compilação do editor web, mas não remove os limites de Things, variáveis ou retenção do serviço Cloud.

## Arquivos e segredos

- `thingProperties.h`: definições geradas para a Thing e conexão.
- `arduino_secrets.h`: SSID, senha, Device ID e Secret Key; não versionar.
- `arduino_secrets.example.h`: modelo seguro que pode ser publicado.

## Dispositivo offline

Confirme rede 2,4 GHz, credenciais, Device ID, Secret Key, associação correta à Thing, `ArduinoCloud.update()` no loop e horário/certificados. Apague e recadastre o dispositivo somente depois de verificar esses itens, porque isso gera novas credenciais.
