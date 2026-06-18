const int GPIO_LED_R_PWM_SAIDA = 25;
const int GPIO_LED_G_PWM_SAIDA = 26;
const int GPIO_LED_B_PWM_SAIDA = 27;
const bool LED_RGB_ANODO_COMUM = false;

void escreverCanal(int gpio, int valor) {
  analogWrite(gpio, LED_RGB_ANODO_COMUM ? 255 - valor : valor);
}

void definirCor(int r, int g, int b, const char *nome) {
  escreverCanal(GPIO_LED_R_PWM_SAIDA, r);
  escreverCanal(GPIO_LED_G_PWM_SAIDA, g);
  escreverCanal(GPIO_LED_B_PWM_SAIDA, b);
  Serial.println(nome);
  delay(1000);
}

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED_R_PWM_SAIDA, OUTPUT);
  pinMode(GPIO_LED_G_PWM_SAIDA, OUTPUT);
  pinMode(GPIO_LED_B_PWM_SAIDA, OUTPUT);
}

void loop() {
  definirCor(255, 0, 0, "Vermelho");
  definirCor(0, 255, 0, "Verde");
  definirCor(0, 0, 255, "Azul");
  definirCor(255, 128, 0, "Laranja");
  definirCor(255, 255, 255, "Branco");
  definirCor(0, 0, 0, "Desligado");
}
