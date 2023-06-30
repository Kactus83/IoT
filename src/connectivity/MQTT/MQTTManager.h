#ifndef MQTTMANAGER_H
#define MQTTMANAGER_H

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "../../config/Config.h"
#include "../messages/MessageHandler.h"

class MQTTManager {
private:
  WiFiClient& wifiClient;
  PubSubClient mqttClient;
  MQTTConfig& mqttConfig;
  MessageHandler* messageHandler;

public:
  MQTTManager(WiFiClient& wifiClient, MQTTConfig& mqttConfig, MessageHandler* messageHandler);
  static void staticCallback(char* topic, byte* payload, unsigned int length);
  void nonStaticCallback(char* topic, byte* payload, unsigned int length);
  void begin();
  void update();
  void sendMQTTMessage(const char* topic, const char* payload);
  void subscribeToTopic(const char* topic);

  static MQTTManager* instance;
};

#endif // MQTTMANAGER_H
