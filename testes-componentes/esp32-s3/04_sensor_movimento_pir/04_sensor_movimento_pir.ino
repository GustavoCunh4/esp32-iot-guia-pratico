const int GPIO_PIR_DIGITAL_ENTRADA = 14;
bool estadoAnterior = false;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_PIR_DIGITAL_ENTRADA, INPUT);
  Serial.println("Aguarde 30-60 s para o PIR estabilizar.");
}

void loop() {
  bool movimento = digitalRead(GPIO_PIR_DIGITAL_ENTRADA) == HIGH;
  if (movimento != estadoAnterior) {
    Serial.println(movimento ? "Movimento detectado" : "Movimento encerrado");
    estadoAnterior = movimento;
  }
  delay(50);
}
