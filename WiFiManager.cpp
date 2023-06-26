#include "WiFiManager.h"

WiFiManager::WiFiManager() : ssid(WiFiConfig::SSID), password(WiFiConfig::PASSWORD) {
}

void WiFiManager::connect() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

WiFiClient& WiFiManager::getWiFiClient() {
  return wifiClient;
}
