// ConnectivityManager.h
#ifndef CONNECTIVITY_MANAGER_H
#define CONNECTIVITY_MANAGER_H

#include "./WiFi/WiFiManager.h"
#include "./MQTT/MQTTManager.h"
#include "../config/Config.h"
#include "./messages/MessageHandler.h"
#include <Arduino.h>

class ConnectivityManager {
private:
  Config& config;
  WiFiManager wifiManager;
  MQTTManager mqttManager;
  MessageHandler messageHandler;

public:
  ConnectivityManager();
  void begin();
  void update();
  void sendMQTTMessage(const char* topic, const char* payload);
};

#endif // CONNECTIVITY_MANAGER_H