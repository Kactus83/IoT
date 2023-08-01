#ifndef SECRET_FACTORY_SETTINGS_H
#define SECRET_FACTORY_SETTINGS_H

#include "../abstract/DTO/FactorySettings.h"

// Definitions for the WiFi and Home Assistant settings
WiFiConfig secretWiFiConfig = {
    "24ghz",
    "PsLyzNnnMBGAcS1jql4H"
};

HomeAssistantConfig secretHAConfig = {
    "192.168.1.98",
    1883,
    "MQTT",
    "MQTT_mqtt_2023!"
};

FactorySettings secretFactorySettings = {
    secretWiFiConfig, 
    secretHAConfig
};

#endif // SECRET_FACTORY_SETTINGS_H
