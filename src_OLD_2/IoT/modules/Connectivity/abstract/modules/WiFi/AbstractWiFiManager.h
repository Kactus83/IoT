#ifndef ABSTRACT_WIFI_MANAGER_H
#define ABSTRACT_WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFiClient.h>
#include "../../../../Config/abstract/DTO/WiFiConfig.h"

class AbstractWiFiManager {
public:
    AbstractWiFiManager() {}

    virtual ~AbstractWiFiManager() {}

    virtual void connect(const WiFiConfig& wifiConfig) = 0;
    virtual bool isConnected() = 0;
    virtual WiFiClient* getClient() = 0;
    virtual void createWiFiAccessPoint() = 0;
    virtual void serveWebPage() = 0;
};

#endif // ABSTRACT_WIFI_MANAGER_H