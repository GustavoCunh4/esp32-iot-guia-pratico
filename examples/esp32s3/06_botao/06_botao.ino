const int GPIO_BOTAO_DIGITAL_ENTRADA = 10;
bool leituraAnterior = HIGH;
bool estadoConfirmado = HIGH;
unsigned long ultimaMudanca = 0;

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_BOTAO_DIGITAL_ENTRADA, INPUT_PULLUP);
}

void loop() {
  bool leitura = digitalRead(GPIO_BOTAO_DIGITAL_ENTRADA);
  if (leitura != leituraAnterior) ultimaMudanca = millis();
  if (millis() - ultimaMudanca > 40 && leitura != estadoConfirmado) {
    estadoConfirmado = leitura;
    Serial.println(estadoConfirmado == LOW ? "Botao PRESSIONADO" : "Botao SOLTO");
  }
  leituraAnterior = leitura;
}
