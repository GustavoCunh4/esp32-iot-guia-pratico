const int GPIO_JOYSTICK_X_ADC1_ENTRADA = 36;
const int GPIO_JOYSTICK_Y_ADC1_ENTRADA = 39;
const int GPIO_JOYSTICK_SW_DIGITAL_ENTRADA = 14;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  pinMode(GPIO_JOYSTICK_SW_DIGITAL_ENTRADA, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(GPIO_JOYSTICK_X_ADC1_ENTRADA);
  int y = analogRead(GPIO_JOYSTICK_Y_ADC1_ENTRADA);
  bool pressionado = digitalRead(GPIO_JOYSTICK_SW_DIGITAL_ENTRADA) == LOW;
  const char *horizontal = x < 1400 ? "ESQUERDA" : (x > 2700 ? "DIREITA" : "CENTRO");
  const char *vertical = y < 1400 ? "BAIXO" : (y > 2700 ? "CIMA" : "CENTRO");
  Serial.printf("X:%4d %-8s | Y:%4d %-6s | SW:%s\n", x, horizontal, y, vertical,
                pressionado ? "PRESSIONADO" : "SOLTO");
  delay(250);
}
