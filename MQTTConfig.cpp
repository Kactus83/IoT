#include "MQTTConfig.h"

const char* MQTTConfig::SERVER = "192.168.1.98";
const int MQTTConfig::PORT = 1883;
const char* MQTTConfig::USERNAME = "MQTT";
const char* MQTTConfig::PASSWORD = "MQTT_mqtt_2023!";
const char* MQTTConfig::MAIN_TOPIC = "flo_perso";

String MQTTConfig::getDiscoveryTopic() {
  return String(MAIN_TOPIC) + "/discovery";
}

String MQTTConfig::getSetTopic(const String& unique_id) {
  return String(MAIN_TOPIC) + "/" + unique_id + "/set";
}

String MQTTConfig::getGetTopic(const String& unique_id) {
  return String(MAIN_TOPIC) + "/" + unique_id + "/get";
}
