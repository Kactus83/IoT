#ifndef ABSTRACT_STORAGE_MANAGER_H
#define ABSTRACT_STORAGE_MANAGER_H

#include "../../DTO/WiFiConfig.h"
#include "../../DTO/HomeAssistantConfig.h"

class AbstractStorageManager {
public:
    virtual WiFiConfig getWiFiSettings() = 0;
    virtual void setWiFiSettings(WiFiConfig wificonfig) = 0;
    
    virtual HomeAssistantConfig getHomeAssistantSettings() = 0;
    virtual void setHomeAssistantSettings(HomeAssistantConfig haconfig) = 0;
};

#endif // ABSTRACT_STORAGE_MANAGER_H
