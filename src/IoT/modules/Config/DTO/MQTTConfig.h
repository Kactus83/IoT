#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

#include <Arduino.h>

struct MQTTConfig {
    const char* CLIENT_ID;
    const char* SERVER;
    int PORT;
    const char* USERNAME;
    const char* PASSWORD;
    int8_t MAX_TOPIC;
};

#endif // MQTT_CONFIG_H
