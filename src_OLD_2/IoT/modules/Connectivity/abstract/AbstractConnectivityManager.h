#ifndef ABSTRACT_CONNECTIVITY_MANAGER_H
#define ABSTRACT_CONNECTIVITY_MANAGER_H

#include <Arduino.h>
#include "../../Config/abstract/AbstractConfigsManager.h"
#include "modules/FrontEndConnector/FrontEndConnectorInterface.h"
#include "modules/Standalone/AbstractStandaloneModule.h"

template <class TWiFiManager, class TStandaloneModule, class... TFrontEndConnectors>
class AbstractConnectivityManager {
public:
    AbstractConnectivityManager(TWiFiManager& wifiManager, AbstractConfigsManager& configsManager, TStandaloneModule& standaloneModule, TFrontEndConnectors&... frontEndConnectors) 
    : wifiManager(wifiManager), configsManager(configsManager), standaloneModule(standaloneModule), frontEndConnectors{&frontEndConnectors...} {}

    void connect() {
        WiFiConfig wifiConfig = configsManager.getWiFiConfig();
        wifiManager.connect(wifiConfig);

        for (auto& connector : frontEndConnectors) {
            connector->connect();
        }
    }

    void updateConnection() {
        if (!wifiManager.isConnected()) {
            WiFiConfig wifiConfig = configsManager.getWiFiConfig();
            wifiManager.connect(wifiConfig);
        }

        for (auto& connector : frontEndConnectors) {
            if (!connector->isConnected()) {
                connector->connect();
            }
        }
    }

    void registerEntity() {
        for (auto& connector : frontEndConnectors) {
            connector->registerEntity();
        }
    }

    void sendMessage(const char* topic, const char* message) {
        for (auto& connector : frontEndConnectors) {
            connector->sendMessage(topic, message);
        }
    }

    void triggerStandaloneMode() {
        standaloneModule.triggerMode();
    }

private:
    TWiFiManager& wifiManager;
    AbstractConfigsManager& configsManager;
    TStandaloneModule& standaloneModule;
    FrontEndConnectorInterface* frontEndConnectors[sizeof...(TFrontEndConnectors)];
};

#endif // ABSTRACT_CONNECTIVITY_MANAGER_H
