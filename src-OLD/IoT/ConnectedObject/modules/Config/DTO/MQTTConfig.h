#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <Arduino.h>

struct MQTTConfig {
    String CLIENT_ID;
    String SERVER;
    int PORT;
    String USERNAME;
    String PASSWORD;
    int MAX_TOPIC;
};

#endif // MQTT_CONFIG_H
