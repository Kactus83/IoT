#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <Arduino.h>
#include "WiFiManagerInterface.h"
#include "../../../../Config/DTO/WiFiConfig.h"

class WiFiManager : public WiFiManagerInterface {
public:
    WiFiManager(const WiFiConfig& wifiConfig) : wifiConfig(wifiConfig) {}

    void connect() override {
        if (!isConnected()) {
            // The specific code to connect should be implemented by subclasses.
            connectToWiFi();
        }
    }

    bool isConnected() override {
        // This function should be implemented by subclasses.
        return isConnectedToWiFi();
    }

    void* getClient() override {
        // This function should be implemented by subclasses.
        return getWiFiClient();
    }

protected:
    WiFiConfig wifiConfig;

    virtual void connectToWiFi() = 0;
    virtual bool isConnectedToWiFi() = 0;
    virtual void* getWiFiClient() = 0;
};

#endif
