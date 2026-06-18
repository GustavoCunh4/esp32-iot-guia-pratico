const int GPIO_LDR_ADC1_ENTRADA = 35;

int lerMediaADC() {
  long soma = 0;
  for (int i = 0; i < 16; i++) {
    soma += analogRead(GPIO_LDR_ADC1_ENTRADA);
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
  const char *estado = leitura >= 2000 ? "CLARO" : "ESCURO";
  Serial.printf("LDR ADC1: %d/4095 | %.1f %% | %s\n", leitura,
                leitura * 100.0f / 4095.0f, estado);
  delay(500);
}
