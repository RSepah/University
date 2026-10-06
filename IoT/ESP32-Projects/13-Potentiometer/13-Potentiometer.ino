const int ADC_PIN=34;
void setup(){ Serial.begin(115200); analogReadResolution(12); analogSetAttenuation(ADC_11db); }
void loop(){ Serial.println(analogRead(ADC_PIN)); delay(500); }
