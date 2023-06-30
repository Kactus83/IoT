#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

class DeviceConfig {
public:
    DeviceConfig(const char* integrationName, const char* deviceName, const char* unicId)
        : INTEGRATION_NAME(integrationName), UNIQUE_ID(unicId), DEVICE_NAME(deviceName) {}
    const char* getIntegrationName() { return INTEGRATION_NAME; }
    const char* getDeviceName() { return DEVICE_NAME; }
    const char* getUnicId() { return UNIQUE_ID; }

private:
    const char* INTEGRATION_NAME;
    const char* DEVICE_NAME;
    const char* UNIQUE_ID;
};

#endif // DEVICE_CONFIG_H
