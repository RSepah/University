#include <DIYables_ESP32_WebServer.h>
const char WIFI_SSID[] = "YOUR_WIFI_SSID";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";
DIYables_ESP32_WebServer server;
void handleHome(WiFiClient& client, const String& method, const String& request, const QueryParams& params, const String& jsonData) {
  server.sendResponse(client, "<html><body><h1>Hello, ESP32!</h1></body></html>");
}
void setup() {
  Serial.begin(9600);
  delay(1000);
  server.addRoute("/", handleHome);
  server.begin(WIFI_SSID, WIFI_PASSWORD);
}
void loop() { server.handleClient(); }