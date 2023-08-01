#ifndef CONNECTIVITY_CONFIG_H
#define CONNECTIVITY_CONFIG_H

#include "WiFiConfig.h"
#include "MQTTConfig.h"

struct ConnectivityConfig {
    WiFiConfig wifiConfig;
    MQTTConfig mqttConfig;
};

#endif // CONNECTIVITY_CONFIG_H
