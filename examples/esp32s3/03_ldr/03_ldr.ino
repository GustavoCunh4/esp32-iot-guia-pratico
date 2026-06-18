const int GPIO_LDR_ADC_ENTRADA = 18;

int lerMediaADC() {
  long soma = 0;
  for (int i = 0; i < 16; i++) {
    soma += analogRead(GPIO_LDR_ADC_ENTRADA);
    delay(2);
  }
  return soma / 16;
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int leitura = lerMediaADC();
  float percentual = leitura * 100.0f / 4095.0f;
  const char *estado = leitura >= 2000 ? "CLARO" : "ESCURO";
  Serial.printf("LDR ADC: %d/4095 | %.1f %% | %s\n", leitura, percentual, estado);
  delay(500);
}
