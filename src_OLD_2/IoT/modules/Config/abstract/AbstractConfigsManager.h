#ifndef ABSTRACT_CONFIGS_MANAGER_H
#define ABSTRACT_CONFIGS_MANAGER_H

#include "DTO/DeviceConfig.h"
#include "DTO/HardwareConfig.h"
#include "DTO/HomeAssistantConfig.h"
#include "./modules/StorageManager/AbstractStorageManager.h"

template<class TDeviceConfig, class TStorageManager, class THardwareConfig>
class AbstractConfigsManager {
public:
    AbstractConfigsManager()
        : isValid_WiFiConfig(false),
          isValid_HomeAssistantConfig(false)
    {}

    void initializeUserSettings() {
        auto wificonfig = storageManager.getWiFiSettings();
        isValid_WiFiConfig = wificonfig.isValid();
        
        auto haconfig = storageManager.getHomeAssistantSettings();
        isValid_HomeAssistantConfig = haconfig.isValid();
    }

private:
    TStorageManager storageManager;
public:
    bool isValid_WiFiConfig;
    bool isValid_HomeAssistantConfig;
};

#endif // ABSTRACT_CONFIGS_MANAGER_H
