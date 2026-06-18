# Bluetooth e BLE

## Diferença entre as placas

| Recurso | DOIT ESP32 | ESP32-S3 |
|---|---:|---:|
| BLE | Sim | Sim |
| Bluetooth Classic | Sim | Não |
| Serial Bluetooth `BluetoothSerial` | Sim | Não |

## BLE: dependências externas

- celular ou computador com BLE;
- aplicativo como [nRF Connect for Mobile](https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-mobile);
- permissões de Bluetooth e, conforme o Android, dispositivos próximos/localização.

O exemplo `ble_led` anuncia um dispositivo, oferece uma característica legível/escrevível e aceita `1` ou `0` para controlar o LED. BLE normalmente não aparece como porta serial.

## Bluetooth Classic: dependências externas

- somente DOIT ESP32 DEVKIT V1;
- celular Android ou computador com Bluetooth Classic;
- aplicativo de terminal Bluetooth serial;
- pareamento com o dispositivo `ESP32-Serial`.

iOS não oferece o mesmo fluxo genérico de Serial Port Profile. Para compatibilidade entre Android e iOS, prefira BLE.

## Segurança

Os exemplos são didáticos e não implementam autenticação forte. Não use comandos BLE/Classic abertos para fechaduras, alarmes ou cargas reais sem projeto de segurança.
