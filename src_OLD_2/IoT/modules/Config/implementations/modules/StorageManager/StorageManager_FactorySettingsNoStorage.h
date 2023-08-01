#ifndef STORAGE_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H
#define STORAGE_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H

#include "../../../secret/secretFactorySettings.h"
#include "../../../abstract/modules/StorageManager/AbstractStorageManager.h"

class StorageManager_FactorySettingsNoStorage : public AbstractStorageManager {
public:
    WiFiConfig getWiFiSettings() override {
        return secretFactorySettings.defaultWiFiConfig;
    }

    void setWiFiSettings(WiFiConfig wificonfig) override {
        secretFactorySettings.defaultWiFiConfig = wificonfig;
    }

    HomeAssistantConfig getHomeAssistantSettings() override {
        return secretFactorySettings.defaultHAConfig;
    }

    void setHomeAssistantSettings(HomeAssistantConfig haconfig) override {
        secretFactorySettings.defaultHAConfig = haconfig;
    }
};

#endif // STORAGE_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H
