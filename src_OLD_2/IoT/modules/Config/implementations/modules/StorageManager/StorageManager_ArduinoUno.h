#ifndef STORAGE_MANAGER_ARDUINO_UNO_H
#define STORAGE_MANAGER_ARDUINO_UNO_H

#include <EEPROM.h>
#include "../../../abstract/modules/StorageManager/AbstractStorageManager.h"
#include "../../../abstract/DTO/WiFiConfig.h"
#include "../../../abstract/DTO/HomeAssistantConfig.h"

class StorageManager_ArduinoUno : public AbstractStorageManager {
public:
    WiFiConfig getWiFiSettings() override {
        WiFiConfig config;
        EEPROM.get(0, config);
        return config;
    }

    void setWiFiSettings(WiFiConfig wificonfig) override {
        EEPROM.put(0, wificonfig);
    }

    HomeAssistantConfig getHomeAssistantSettings() override {
        HomeAssistantConfig config;
        EEPROM.get(sizeof(WiFiConfig), config);  // Read starting after WiFiConfig
        return config;
    }

    void setHomeAssistantSettings(HomeAssistantConfig haconfig) override {
        EEPROM.put(sizeof(WiFiConfig), haconfig); // Write starting after WiFiConfig
    }
};

#endif // STORAGE_MANAGER_ARDUINO_UNO_H
