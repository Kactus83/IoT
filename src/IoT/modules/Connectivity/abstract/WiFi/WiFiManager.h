#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <Arduino.h>
#include <WiFiClient.h>
#include "../../../Config/DTO/WiFiConfig.h"

class WiFiManager {
public:
    WiFiManager(const WiFiConfig& wifiConfig) : wifiConfig(wifiConfig) {}

    virtual ~WiFiManager() {}

    virtual void connect() = 0;
    virtual bool isConnected() = 0;
    virtual WiFiClient* getClient() = 0;

protected:
    const WiFiConfig& wifiConfig;
};

#endif
