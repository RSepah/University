#include <WiFi.h>
const char* ssid="YOUR_SSID";
const char* password="YOUR_PASSWORD";
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){ delay(500); Serial.print("."); }
  Serial.println(); Serial.println("WiFi connected"); Serial.println(WiFi.localIP());
}
void loop(){}
