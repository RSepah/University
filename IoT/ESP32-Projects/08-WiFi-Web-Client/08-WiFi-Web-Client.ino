#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid="YOUR_SSID";
const char* password="YOUR_PASSWORD";
void setup(){
  Serial.begin(115200); WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED) delay(500);
  HTTPClient http; http.begin("http://example.com/");
  int code=http.GET(); Serial.printf("HTTP code: %d\n",code);
  if(code>0) Serial.println(http.getString()); http.end();
}
void loop(){}
