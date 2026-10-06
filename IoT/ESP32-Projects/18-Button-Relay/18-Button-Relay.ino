#define BUTTON_PIN 22
#define RELAY_PIN 27
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
}
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW) {
    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    Serial.println("The button is unpressed");
    digitalWrite(RELAY_PIN, LOW);
  }
}