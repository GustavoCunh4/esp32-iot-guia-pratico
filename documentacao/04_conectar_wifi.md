# Wi-Fi no ESP32

## O que é necessário externamente

- roteador ou hotspot em 2,4 GHz;
- nome da rede (SSID) e senha;
- computador com Arduino IDE;
- cabo USB de dados;
- para abrir o servidor web, celular ou computador na mesma rede.

ESP32 e ESP32-S3 usam Wi-Fi 2,4 GHz. Uma rede configurada exclusivamente em 5 GHz não aparecerá. Redes corporativas, captive portals e WPA-Enterprise precisam de configuração específica e não fazem parte dos exemplos básicos.

## Exemplos

- `01_procurar_redes_wifi`: procura redes sem precisar de senha.
- `02_conectar_wifi_segredos_separados`: conecta usando um arquivo `.h` não versionado.
- `03_conectar_wifi_arquivo_unico`: mesma conexão com tudo dentro do `.ino`.
- `04_servidor_web_led_segredos_separados`: servidor web com credenciais fora do sketch.
- `05_servidor_web_led_arquivo_unico`: servidor web completo em um `.ino`.
- `06_controlar_led_ble`: controla um LED por BLE.
- `07_controlar_led_bluetooth_classico`: somente no DOIT ESP32 DEVKIT V1.

## Credenciais

Na versão com segredos separados, copie `segredos_arduino.exemplo.h` para `segredos_arduino.h` na mesma pasta do sketch e preencha:

```cpp
#define SECRET_SSID "nome-da-rede"
#define SECRET_PASS "senha-da-rede"
```

O arquivo real está no `.gitignore`. Na versão de arquivo único, preencha as constantes no começo do `.ino`; não envie esse arquivo ao GitHub depois de colocar uma senha real.

## Diagnóstico

- `WL_NO_SSID_AVAIL`: rede não encontrada; confirme 2,4 GHz e SSID.
- `WL_CONNECT_FAILED`: senha ou segurança incompatível.
- Conecta e cai: verifique sinal, fonte e reinicializações.
- Tem IP mas a página não abre: confirme que cliente e ESP32 estão na mesma rede e use `http://IP_MOSTRADO/`.
