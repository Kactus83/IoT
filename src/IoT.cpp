#include "settings.h"
#include "IoT/modules/Config/ConfigManager.h"
#include "IoT/modules/Entities/EntitiesManager.h"
#include "IoT/modules/Connectivity/implementations/ArduinoUno/ConnectivityManager_ArduinoUno.h"

ConfigManager configManager(factorySettings);
EntitiesManager entitiesManager(configManager.getDeviceConfig());
ConnectivityManager_ArduinoUno connectivityManager(entitiesManager, configManager.getConnectivityConfig());

void setup() {
    // Connect to Home Assistant
    connectivityManager.connectHomeAssistant();
}

void loop() {
}
