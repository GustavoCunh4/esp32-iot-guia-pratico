const int GPIO_BUZZER_PWM_SAIDA = 18;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_BUZZER_PWM_SAIDA, OUTPUT);
}

void loop() {
  const int frequencias[] = {262, 330, 392, 523};
  for (int frequencia : frequencias) {
    Serial.printf("Tom: %d Hz\n", frequencia);
    tone(GPIO_BUZZER_PWM_SAIDA, frequencia, 250);
    delay(350);
  }
  noTone(GPIO_BUZZER_PWM_SAIDA);
  Serial.println("Pausa");
  delay(1500);
}
