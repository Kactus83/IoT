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
            {factorySettings.DEVICE_NAME + "_" + factorySettings.UNIQUE_ID, factorySettings.MQTT_SERVER, factorySettings.MQTT_PORT, factorySettings.MQTT_USERNAME, factorySettings.MQTT_PASSWORD}
        }) {}


    DeviceConfig getDeviceConfig() const {
        return deviceConfig;
    }

    ConnectivityConfig getConnectivityConfig() const {
        return connectivityConfig;
    }

private:
    DeviceConfig deviceConfig;
    ConnectivityConfig connectivityConfig;
};

#endif // CONFIG_MANAGER_H
