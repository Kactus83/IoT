#ifndef CONNECTIVITYMANAGER_ARDUINO_UNO_H
#define CONNECTIVITYMANAGER_ARDUINO_UNO_H

#include <Arduino.h>
#include "../../abstract/ConnectivityManager.h"
#include "../common/WiFi/WiFiManager_WiFiNina.h"
#include "../common/MQTT/MQTTManager_PubSubClient.h"

class ConnectivityManager_ArduinoUno : public ConnectivityManager<WiFiManager_WiFiNina, MQTTManager_PubSubClient> {
public:
    ConnectivityManager_ArduinoUno(EntitiesManagerInterface& entitiesManager, ConnectivityConfig& connectivityConfig)
    : ConnectivityManager<WiFiManager_WiFiNina, MQTTManager_PubSubClient>(
        wifiManager,
        mqttManager,
        entitiesManager,
        connectivityConfig
    ),
    wifiManager(connectivityConfig.wifiConfig),
    mqttManager(connectivityConfig.mqttConfig, entitiesManager)
    {}

private:
    WiFiManager_WiFiNina wifiManager;
    MQTTManager_PubSubClient mqttManager;
};

#endif
