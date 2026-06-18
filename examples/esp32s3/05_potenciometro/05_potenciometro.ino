const int GPIO_POTENCIOMETRO_ADC_ENTRADA = 2;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  long soma = 0;
  for (int i = 0; i < 16; i++) soma += analogRead(GPIO_POTENCIOMETRO_ADC_ENTRADA);
  int valor = soma / 16;
  Serial.printf("Potenciometro: %d/4095 | %.1f %%\n", valor, valor * 100.0f / 4095.0f);
  delay(300);
}
