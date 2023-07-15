#include "settings.h"
#include "IoT/modules/Config/ConfigManager.h"
#include "IoT/modules/Entities/EntitiesManager.h"
#include "IoT/modules/Connectivity/implementations/ArduinoUno/ConnectivityManager_ArduinoUno.h"

class IoTController {
    ConfigManager configManager;
    EntitiesManager entitiesManager;
    ConnectivityManager_ArduinoUno connectivityManager;

public:
    IoTController(const FactorySettings& factorySettings)
    : configManager(factorySettings),
      entitiesManager(configManager.getDeviceConfig()),
      connectivityManager(entitiesManager, configManager.getConnectivityConfig()) {
        entitiesManager.setMessagesManager(connectivityManager);
    }

    void setup() {
        entitiesManager.createEntities();
        connectivityManager.connectHomeAssistant();
        entitiesManager.setupEntities();
    }

    void loop() {
        connectivityManager.updateHomeAssistantConnection();
        entitiesManager.entitiesLoop();
    }
};

IoTController controller(factorySettings);

void setup() {
    controller.setup();
}

void loop() {
    controller.loop();
}
