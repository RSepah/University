#include <WiFi.h>
const char* ssid="YOUR_SSID";
const char* password="YOUR_PASSWORD";
WiFiServer server(80);
void setup(){
  Serial.begin(115200); WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP()); server.begin();
}
void loop(){
  WiFiClient client=server.available(); if(!client) return;
  while(client.connected() && !client.available()) delay(1);
  while(client.available()) client.read();
  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<h1>Hello from ESP32</h1>");
  client.stop();
}
