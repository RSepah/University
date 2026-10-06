#include <WiFi.h>
#include <HTTPClient.h>
const char WIFI_SSID[] = "YOUR_WIFI_SSID";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";
String HOST_NAME = "http://YOUR_DOMAIN.com";
String PATH_NAME = "/products/arduino";
String queryString = "temperature=26&humidity=70";
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  HTTPClient http;
  http.begin(HOST_NAME + PATH_NAME);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(queryString);
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) Serial.println(http.getString());
    else Serial.printf("[HTTP] POST... code: %d\n", httpCode);
  } else Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  http.end();
}
void loop() {}