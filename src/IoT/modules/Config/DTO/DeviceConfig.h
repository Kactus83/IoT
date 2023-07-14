#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <Arduino.h>

struct DeviceConfig {
    String INTEGRATION_NAME;
    int MAX_ENTITIES;
    String DEVICE_NAME;
    String UNIQUE_ID;
};

#endif // DEVICE_CONFIG_H