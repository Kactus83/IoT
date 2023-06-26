#ifndef MQTTMANAGER_H
#define MQTTMANAGER_H

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "MessageHandler.h"
#include "MQTTConfig.h"
#include "RGB_LED_Info.h"

class MQTTManager {
  private:
    WiFiClient& wifiClient;
    PubSubClient mqttClient;
    MessageHandler& messageHandler;
    RGB_LED_Info ledInfo;
    void sendState();
    
  public:
    MQTTManager(WiFiClient& wifiClient, MessageHandler& messageHandler);
    void callback(char* topic, byte* payload, unsigned int length);
    void begin();
    void update();
    void registerEntity(const char* payload);
};

#endif
