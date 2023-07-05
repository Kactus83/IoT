#include "WiFiNINA.h" 
#include "../../../abstract/modules/WiFi/WiFiManager.h"

class WiFiManager_WiFiNina : public WiFiManager {
public:
    WiFiManager_WiFiNina(const WiFiConfig& wifiConfig) : WiFiManager(wifiConfig) {}

protected:
    WiFiClient wifiClient;

    void connectToWiFi() override {
        WiFi.begin(wifiConfig.SSID.c_str(), wifiConfig.PASSWORD.c_str());
    }

    bool isConnectedToWiFi() override {
        return WiFi.status() == WL_CONNECTED;
    }

    WiFiClient* getWiFiClient() override {
        return &wifiClient;
    }
};
