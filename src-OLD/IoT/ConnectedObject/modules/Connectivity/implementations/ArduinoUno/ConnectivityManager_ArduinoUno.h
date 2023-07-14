#ifndef CONNECTIVITYMANAGER_ARDUINO_UNO_H
#define CONNECTIVITYMANAGER_ARDUINO_UNO_H

#include <Arduino.h>
#include "../../abstract/ConnectivityManager.h"
#include "../modules/WiFi/WiFiManager_WiFiNina.h"
#include "../modules/MQTT/MQTTManager_PubSubClient.h"
#include "../../../Messages/MessagesManagerInterface.h"

class ConnectivityManager_ArduinoUno : public ConnectivityManager<WiFiManager_WiFiNina, MQTTManager_PubSubClient> {
public:
    ConnectivityManager_ArduinoUno(MessagesManagerInterface& messagesManager, ConnectivityConfig& connectivityConfig)
    : ConnectivityManager<WiFiManager_WiFiNina, MQTTManager_PubSubClient>(*(new WiFiManager_WiFiNina(connectivityConfig.wifiConfig)), *(new MQTTManager_PubSubClient(connectivityConfig.mqttConfig, messagesManager)), messagesManager, connectivityConfig) {}
};

#endif
