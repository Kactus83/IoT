#include "WiFiManager.h"

WiFiManager::WiFiManager(WiFiConfig& wifiConfig)
  : wifiConfig(wifiConfig) {
}

void WiFiManager::connect() {
  WiFi.begin(wifiConfig.getSSID(), wifiConfig.getPassword());
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
