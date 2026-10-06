#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF };
EthernetClient client;
int HTTP_PORT = 80;
String HTTP_METHOD = "GET";
char HOST_NAME[] = "example.com";
String PATH_NAME = "/";
void setup() {
  Serial.begin(9600);
  delay(1000);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to obtaining an IP address");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) Serial.println("Ethernet shield was not found");
    if (Ethernet.linkStatus() == LinkOFF) Serial.println("Ethernet cable is not connected.");
    while (true);
  }
  if (client.connect(HOST_NAME, HTTP_PORT)) {
    client.println(HTTP_METHOD + " " + PATH_NAME + " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println();
    while (client.connected()) if (client.available()) Serial.print((char)client.read());
    client.stop();
  } else Serial.println("connection failed");
}
void loop() {}