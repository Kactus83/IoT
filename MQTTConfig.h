#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <Arduino.h>

class MQTTConfig {
public:
  static const char* SERVER;
  static const int PORT;
  static const char* USERNAME;
  static const char* PASSWORD;
  static const char* MAIN_TOPIC;

  static String getDiscoveryTopic();
  static String getSetTopic(const String& unique_id);
  static String getGetTopic(const String& unique_id);
};

#endif // MQTT_CONFIG_H
