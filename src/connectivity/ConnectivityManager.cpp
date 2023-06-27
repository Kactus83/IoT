#include "ConnectivityManager.h"

ConnectivityManager::ConnectivityManager()
  : config(Config::getInstance()), wifiManager(config.getWifiConfig()), mqttManager(wifiManager.getWiFiClient(), config.getMqttConfig(), &messageHandler) {
}

void ConnectivityManager::begin() {
  wifiManager.connect();
  mqttManager.begin();
}

void ConnectivityManager::update() {
  mqttManager.update();
}

void ConnectivityManager::sendMQTTMessage(const char* topic, const char* payload) {
  mqttManager.sendMQTTMessage(topic, payload);
}
