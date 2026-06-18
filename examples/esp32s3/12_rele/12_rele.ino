// Teste o modulo sem carga nos terminais COM/NO/NC.
const int GPIO_RELE_DIGITAL_SAIDA = 38;
const bool RELE_ATIVO_EM_LOW = true;

void definirRele(bool ligado) {
  digitalWrite(GPIO_RELE_DIGITAL_SAIDA,
               ligado == RELE_ATIVO_EM_LOW ? LOW : HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_RELE_DIGITAL_SAIDA, OUTPUT);
  definirRele(false);
}

void loop() {
  Serial.println("Rele acionado");
  definirRele(true);
  delay(1000);
  Serial.println("Rele desacionado");
  definirRele(false);
  delay(2000);
}
