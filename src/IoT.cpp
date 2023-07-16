#include "settings.h"
#include "IoT/modules/Config/ConfigManager.h"
#include "IoT/modules/Entities/EntitiesManager.h"
#include "IoT/modules/Connectivity/implementations/ArduinoUno/ConnectivityManager_ArduinoUno.h"

class IoTController {
    ConfigManager<WS12_RGB_LED_EntitiesConfig> configManager;
    EntitiesManager entitiesManager;
    ConnectivityManager_ArduinoUno connectivityManager;

public:
    IoTController(const FactorySettings& factorySettings)
    : configManager(factorySettings),
      entitiesManager(configManager.getEntitiesConfig()),
      connectivityManager(entitiesManager, configManager.getConnectivityConfig()) {
        entitiesManager.setMessagesManager(connectivityManager);
    }

    void setup() {
        Serial.begin(9600);
        connectivityManager.connectHomeAssistant();
        entitiesManager.setupEntities();
    }

    void loop() {
        connectivityManager.updateHomeAssistantConnection();
        entitiesManager.entitiesLoop();
        delay(100);
    }
};

IoTController controller(factorySettings);

void setup() {
    controller.setup();
}

void loop() {
    controller.loop();
}
