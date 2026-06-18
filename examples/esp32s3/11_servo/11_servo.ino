#include <ESP32Servo.h>

const int GPIO_SERVO_SINAL_SAIDA = 17;
Servo servo;

void setup() {
  Serial.begin(115200);
  servo.setPeriodHertz(50);
  servo.attach(GPIO_SERVO_SINAL_SAIDA, 500, 2400);
}

void loop() {
  const int angulos[] = {0, 90, 180, 90};
  for (int angulo : angulos) {
    servo.write(angulo);
    Serial.printf("Servo solicitado em %d graus\n", angulo);
    delay(1500);
  }
}
