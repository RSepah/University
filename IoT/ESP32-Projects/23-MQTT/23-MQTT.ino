#include <WiFi.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
const char WIFI_SSID[] = "YOUR_WIFI_SSID";
const char WIFI_PASSWORD[] = "YOUR_WIFI_PASSWORD";
const char MQTT_BROKER_ADRRESS[] = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "YOUR-NAME-esp32-001";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";
const char PUBLISH_TOPIC[] = "YOUR-NAME-esp32-001/loopback";
const char SUBSCRIBE_TOPIC[] = "YOUR-NAME-esp32-001/loopback";
const int PUBLISH_INTERVAL = 5000;
WiFiClient network;
MQTTClient mqtt = MQTTClient(256);
unsigned long lastPublishTime = 0;
void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  connectToMQTT();
}
void loop() {
  mqtt.loop();
  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendToMQTT();
    lastPublishTime = millis();
  }
}
void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
  mqtt.onMessage(messageHandler);
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) { Serial.print("."); delay(100); }
  if (!mqtt.connected()) { Serial.println("ESP32 - MQTT broker Timeout!"); return; }
  mqtt.subscribe(SUBSCRIBE_TOPIC);
}
void sendToMQTT() {
  StaticJsonDocument<200> message;
  message["timestamp"] = millis();
  message["data"] = analogRead(0);
  char messageBuffer[512];
  serializeJson(message, messageBuffer);
  mqtt.publish(PUBLISH_TOPIC, messageBuffer);
}
void messageHandler(String &topic, String &payload) {
  Serial.println("ESP32 - received from MQTT:");
  Serial.println("- topic: " + topic);
  Serial.println("- payload:");
  Serial.println(payload);
}