#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include "./DTO/FactorySettings.h"
#include "./DTO/DeviceConfig.h"
#include "./DTO/ConnectivityConfig.h"

class ConfigManager {
public:
    ConfigManager(const FactorySettings& factorySettings)
        : deviceConfig({factorySettings.INTEGRATION_NAME, factorySettings.MAX_ENTITIES, factorySettings.DEVICE_NAME, factorySettings.UNIQUE_ID}),
          connectivityConfig({
            {factorySettings.WIFI_SSID, factorySettings.WIFI_PASSWORD},
            {getDeviceUniqueId(factorySettings), factorySettings.MQTT_SERVER, factorySettings.MQTT_PORT, factorySettings.MQTT_USERNAME, factorySettings.MQTT_PASSWORD}
          }) {}

    DeviceConfig& getDeviceConfig() {
        return deviceConfig;
    }

    ConnectivityConfig& getConnectivityConfig() {
        return connectivityConfig;
    }

private:
    DeviceConfig deviceConfig;
    ConnectivityConfig connectivityConfig;

    const char* getDeviceUniqueId(const FactorySettings& factorySettings) {
        int bufferSize = strlen(factorySettings.DEVICE_NAME) + strlen(factorySettings.UNIQUE_ID) + 2; // +1 for the underscore and +1 for the null terminator
        char* uniqueId = new char[bufferSize];
        snprintf(uniqueId, bufferSize, "%s_%s", factorySettings.DEVICE_NAME, factorySettings.UNIQUE_ID);
        return uniqueId;
    }
};

#endif // CONFIG_MANAGER_H
