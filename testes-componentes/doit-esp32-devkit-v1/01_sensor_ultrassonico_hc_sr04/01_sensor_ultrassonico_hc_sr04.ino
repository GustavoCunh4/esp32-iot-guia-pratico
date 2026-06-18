// DOIT ESP32: sensor ultrassonico HC-SR04. ECHO exige divisor 1 kΩ / 2 kΩ.
const int GPIO_TRIG_DIGITAL_SAIDA = 33;
const int GPIO_ECHO_DIGITAL_ENTRADA = 34;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_TRIG_DIGITAL_SAIDA, OUTPUT);
  pinMode(GPIO_ECHO_DIGITAL_ENTRADA, INPUT);
  digitalWrite(GPIO_TRIG_DIGITAL_SAIDA, LOW);
}

void loop() {
  digitalWrite(GPIO_TRIG_DIGITAL_SAIDA, LOW);
  delayMicroseconds(2);
  digitalWrite(GPIO_TRIG_DIGITAL_SAIDA, HIGH);
  delayMicroseconds(10);
  digitalWrite(GPIO_TRIG_DIGITAL_SAIDA, LOW);
  unsigned long duracao = pulseIn(GPIO_ECHO_DIGITAL_ENTRADA, HIGH, 30000);
  if (duracao == 0) Serial.println("Sem eco: confira montagem e alcance.");
  else Serial.printf("Distancia: %.1f cm\n", duracao * 0.0343f / 2.0f);
  delay(500);
}
