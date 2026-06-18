# Wi-Fi no ESP32

## O que é necessário externamente

- roteador ou hotspot em 2,4 GHz;
- nome da rede (SSID) e senha;
- computador com Arduino IDE;
- cabo USB de dados;
- para abrir o servidor web, celular ou computador na mesma rede.

ESP32 e ESP32-S3 usam Wi-Fi 2,4 GHz. Uma rede configurada exclusivamente em 5 GHz não aparecerá. Redes corporativas, captive portals e WPA-Enterprise precisam de configuração específica e não fazem parte dos exemplos básicos.

## Exemplos

- `wifi_scan`: procura redes sem precisar de senha.
- `wifi_connect`: conecta, mostra IP, MAC, RSSI e reconecta.
- `web_led`: cria uma página local para ligar e desligar um LED.

## Credenciais

Copie `arduino_secrets.example.h` para `arduino_secrets.h` na mesma pasta do sketch e preencha:

```cpp
#define SECRET_SSID "nome-da-rede"
#define SECRET_PASS "senha-da-rede"
```

O arquivo real está no `.gitignore`. Nunca publique a senha.

## Diagnóstico

- `WL_NO_SSID_AVAIL`: rede não encontrada; confirme 2,4 GHz e SSID.
- `WL_CONNECT_FAILED`: senha ou segurança incompatível.
- Conecta e cai: verifique sinal, fonte e reinicializações.
- Tem IP mas a página não abre: confirme que cliente e ESP32 estão na mesma rede e use `http://IP_MOSTRADO/`.
