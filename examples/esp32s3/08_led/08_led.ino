const int GPIO_LED_DIGITAL_SAIDA = 15;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED_DIGITAL_SAIDA, OUTPUT);
}

void loop() {
  digitalWrite(GPIO_LED_DIGITAL_SAIDA, HIGH);
  Serial.println("LED ligado");
  delay(1000);
  digitalWrite(GPIO_LED_DIGITAL_SAIDA, LOW);
  Serial.println("LED desligado");
  delay(1000);
}
