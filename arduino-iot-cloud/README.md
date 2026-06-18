# Exemplos do Arduino IoT Cloud

Leia primeiro [o guia completo](../documentacao/06_usar_arduino_iot_cloud.md).

Cada placa possui duas versões do mesmo projeto com cinco variáveis, respeitando o limite informado para o plano gratuito em 18/06/2026:

- `lampada_cloud_arquivo_unico`: credenciais, propriedades e programa em um único `.ino`;
- `lampada_cloud_arquivos_separados`: programa, propriedades e credenciais em arquivos diferentes.

A versão de arquivo único é mais simples para estudar. A versão separada é mais segura para projetos publicados no GitHub.

## Antes de compilar

1. Crie o Device e a Thing na Arduino Cloud.
2. Crie `ledCloud`, `temperaturaCloud`, `luminosidadeCloud`, `potenciometroCloud` e `botaoCloud` com os tipos descritos no guia.
3. Na versão separada, copie `segredos_arduino.exemplo.h` para `segredos_arduino.h`.
4. Na versão de arquivo único, preencha as constantes no começo do `.ino`.
5. Preencha Wi-Fi, Device Login Name/ID e Secret Device Key.
6. Instale `ArduinoIoTCloud`, `Arduino_ConnectionHandler`, `DHT sensor library` e `Adafruit Unified Sensor`.

Nunca envie `segredos_arduino.h` ao GitHub. Se usar arquivo único, não faça commit depois de inserir credenciais reais.
