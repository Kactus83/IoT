#ifndef ABSTRACT_STANDALONE_MODULE_H
#define ABSTRACT_STANDALONE_MODULE_H

#include <Arduino.h>
#include "../../../../Config/abstract/DTO/DeviceConfig.h"
#include "../WiFi/AbstractWiFiManager.h"

class AbstractStandaloneModule {
public:
    AbstractStandaloneModule(AbstractWiFiManager& wifiManager, const DeviceConfig& deviceConfig) 
    : wifiManager(wifiManager), deviceConfig(deviceConfig) {}

    virtual ~AbstractStandaloneModule() {}

    virtual void triggerMode() = 0;

protected:
    AbstractWiFiManager& wifiManager;
    const DeviceConfig& deviceConfig;
};

#endif // ABSTRACT_STANDALONE_MODULE_H