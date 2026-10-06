#define SIM800_RX 16
#define SIM800_TX 17
HardwareSerial sim800(2);
void setup() {
  Serial.begin(115200);
  sim800.begin(9600, SERIAL_8N1, SIM800_RX, SIM800_TX);
  Serial.println("Initializing SIM800L...");
  delay(1000);
  sim800.println("AT"); updateSerial();
  sim800.println("AT+CSQ"); updateSerial();
  sim800.println("AT+CCID"); updateSerial();
  sim800.println("AT+CREG?"); updateSerial();
}
void loop() { updateSerial(); }
void updateSerial() {
  delay(100);
  while (Serial.available()) sim800.write(Serial.read());
  while (sim800.available()) Serial.write(sim800.read());
}