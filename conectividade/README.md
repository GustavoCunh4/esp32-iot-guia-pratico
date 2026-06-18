# Exemplos de conectividade

Os nomes de pastas indicam exatamente a placa e o objetivo do teste.

Para os exemplos que usam credenciais existem duas opções:

- **`segredos_separados`**: opção recomendada para GitHub. O código fica no `.ino` e as credenciais ficam em `segredos_arduino.h`, que não é versionado.
- **`arquivo_unico`**: tudo fica dentro de um único `.ino`, como em um sketch simples da Arduino IDE. Preencha as credenciais diretamente no começo do arquivo e não publique esse arquivo depois de inserir senhas reais.

Cada alternativa está em uma pasta diferente. Não coloque as duas versões na mesma pasta, pois ambas possuem `setup()` e `loop()`.

Leia também os guias de [Wi-Fi](../documentacao/04_conectar_wifi.md) e [Bluetooth](../documentacao/05_conectar_bluetooth_e_ble.md).
