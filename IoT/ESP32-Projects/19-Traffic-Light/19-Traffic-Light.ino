#define PIN_RED 25
#define PIN_YELLOW 26
#define PIN_GREEN 27
#define RED_TIME 4000
#define YELLOW_TIME 4000
#define GREEN_TIME 4000
void setup() {
  pinMode(PIN_RED, OUTPUT); pinMode(PIN_YELLOW, OUTPUT); pinMode(PIN_GREEN, OUTPUT);
}
void loop() {
  digitalWrite(PIN_RED,HIGH); digitalWrite(PIN_YELLOW,LOW); digitalWrite(PIN_GREEN,LOW); delay(RED_TIME);
  digitalWrite(PIN_RED,LOW); digitalWrite(PIN_YELLOW,HIGH); digitalWrite(PIN_GREEN,LOW); delay(YELLOW_TIME);
  digitalWrite(PIN_RED,LOW); digitalWrite(PIN_YELLOW,LOW); digitalWrite(PIN_GREEN,HIGH); delay(GREEN_TIME);
}