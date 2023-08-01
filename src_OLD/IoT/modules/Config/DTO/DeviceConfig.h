#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <Arduino.h>

struct DeviceConfig {
    const char* INTEGRATION_NAME;
    int8_t MAX_ENTITIES;
    const char* DEVICE_NAME;
    const char* UNIQUE_ID;
};

#endif // DEVICE_CONFIG_H
