const int BUTTON_PIN=14;
const int LED_PIN=13;
void setup(){ pinMode(BUTTON_PIN,INPUT_PULLUP); pinMode(LED_PIN,OUTPUT); }
void loop(){ digitalWrite(LED_PIN,digitalRead(BUTTON_PIN)==LOW?HIGH:LOW); }
