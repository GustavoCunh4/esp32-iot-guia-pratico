const int GPIO_POTENCIOMETRO_ADC1_ENTRADA = 32;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  long soma = 0;
  for (int i = 0; i < 16; i++) soma += analogRead(GPIO_POTENCIOMETRO_ADC1_ENTRADA);
  int valor = soma / 16;
  Serial.printf("Potenciometro ADC1: %d/4095 | %.1f %%\n", valor,
                valor * 100.0f / 4095.0f);
  delay(300);
}
