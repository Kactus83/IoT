#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include "./secret/FactorySettings.h"
#include "./DTO/DeviceConfig.h"
#include "./DTO/ConnectivityConfig.h"

class ConfigManager {
public:
    ConfigManager(const FactorySettings& factorySettings)
        : deviceConfig({factorySettings.INTEGRATION_NAME, factorySettings.DEVICE_NAME, factorySettings.UNIQUE_ID}),
          connectivityConfig({{factorySettings.WIFI_SSID, factorySettings.WIFI_PASSWORD},
                               {factorySettings.MQTT_SERVER, factorySettings.MQTT_PORT, factorySettings.MQTT_USERNAME, factorySettings.MQTT_PASSWORD, factorySettings.MAX_TOPIC}}) {}

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
