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

void ConnectivityManager::subscribeToTopic(const char* topic) {
  mqttManager.subscribeToTopic(topic);
}

String ConnectivityManager::getLastMQTTMessage(const char* topic) {
  String lastMessage = messageHandler.getLastMessage(topic);
  return lastMessage;
}

void ConnectivityManager::clearLastMQTTMessage(const char* topic) {
  messageHandler.clearLastMessage(topic);
}
