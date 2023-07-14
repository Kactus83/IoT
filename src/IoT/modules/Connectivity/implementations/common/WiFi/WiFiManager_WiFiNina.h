#ifndef WIFIMANAGER_WIFININA_H
#define WIFIMANAGER_WIFININA_H

#include <WiFiNINA.h>
#include "../../../abstract/WiFi/WiFiManager.h"

class WiFiManager_WiFiNina : public WiFiManager {
public:
    WiFiManager_WiFiNina(const WiFiConfig& wifiConfig) : WiFiManager(wifiConfig), wifiClient() {}

    void connect() override {
        WiFi.begin(wifiConfig.SSID.c_str(), wifiConfig.PASSWORD.c_str());
    }

    bool isConnected() override {
        return WiFi.status() == WL_CONNECTED;
    }

    WiFiClient* getClient() override {
        return &wifiClient;
    }

private:
    WiFiClient wifiClient;
};

#endif
