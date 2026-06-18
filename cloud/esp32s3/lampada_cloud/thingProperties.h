#pragma once
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "arduino_secrets.h"

const char DEVICE_LOGIN_NAME[] = SECRET_DEVICE_LOGIN_NAME;
const char SSID[] = SECRET_SSID;
const char PASS[] = SECRET_OPTIONAL_PASS;
const char DEVICE_KEY[] = SECRET_DEVICE_KEY;

bool ledCloud;
float temperaturaCloud;
int luminosidadeCloud;
int potenciometroCloud;
bool botaoCloud;

void onLedCloudChange();

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(ledCloud, READWRITE, ON_CHANGE, onLedCloudChange);
  ArduinoCloud.addProperty(temperaturaCloud, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(luminosidadeCloud, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(potenciometroCloud, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(botaoCloud, READ, ON_CHANGE, NULL);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
