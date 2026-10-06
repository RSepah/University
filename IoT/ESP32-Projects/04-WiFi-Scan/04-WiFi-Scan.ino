#include <WiFi.h>
void setup(){ Serial.begin(115200); WiFi.mode(WIFI_STA); WiFi.disconnect(); delay(100); }
void loop(){ int n=WiFi.scanNetworks(); Serial.printf("Networks found: %d\n",n); for(int i=0;i<n;i++) Serial.printf("%d: %s (%d dBm)\n",i+1,WiFi.SSID(i).c_str(),WiFi.RSSI(i)); WiFi.scanDelete(); delay(5000); }
