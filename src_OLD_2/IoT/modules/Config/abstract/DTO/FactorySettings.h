#ifndef FACTORY_SETTINGS_H
#define FACTORY_SETTINGS_H

#include "./WiFiConfig.h"
#include "./HomeAssistantConfig.h"

struct FactorySettings {
    WiFiConfig defaultWiFiConfig;
    HomeAssistantConfig defaultHAConfig;
};

#endif // FACTORY_SETTINGS_H
