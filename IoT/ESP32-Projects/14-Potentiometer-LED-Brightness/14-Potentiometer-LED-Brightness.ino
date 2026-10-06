#define POTENTIOMETER_PIN 36
#define LED_PIN 21
void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  int analogValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(analogValue, 0, 4095, 0, 255);
  analogWrite(LED_PIN, brightness);
  Serial.print("Analog value = ");
  Serial.print(analogValue);
  Serial.print(" => brightness = ");
  Serial.println(brightness);
  delay(100);
}