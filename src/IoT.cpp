#include "IoT/implementations/common/Hardware/Sensors/SDS011/HardwareDeviceModule_SDS011.h"
#include "IoT/implementations/common/Hardware/Sensors/SDC30/HardwareDeviceModule_SDC30.h" // Inclure l'entête du module SDC30
#include <Arduino.h>
#include <ArduinoJson.h> // Inclure la bibliothèque pour manipuler JSON

// Define global variables
HardwareDeviceModule_SDS011* sds011Module;
HardwareDeviceModule_SDC30* sdc30Module; // Définir le module SDC30

// Define the interval for logs
const long interval = 10000; // 10 seconds
unsigned long previousMillis = 0;  // will store the last time logs were displayed

// Declare functions
void logEntitiesContainer(EntitiesContainerInterface* container);
void logHardwareState(EntitiesContainerInterface* container);

void setup() {

    // Initialize serial communication
    Serial.begin(9600); 
    while(!Serial) { } // Wait until the Serial is available

    // Initialize the SDS011 module
    sds011Module = new HardwareDeviceModule_SDS011(0, 1); // Suppose that SDS011 sensor is connected to pins 0 and 1

    // Initialize the SDC30 module
    sdc30Module = new HardwareDeviceModule_SDC30(); // Veuillez adapter cette ligne en fonction de vos paramètres de configuration pour le SDC30

    // Setup the hardware
    sds011Module->setupHardwareDevice();
    sdc30Module->setupHardwareDevice(); // Configuration du matériel SDC30

    // Log container data for both modules
    logEntitiesContainer(sds011Module->entitiesContainer);
    logEntitiesContainer(sdc30Module->entitiesContainer); // Log des entités du module SDC30

    Serial.println("Setup completed, starting loop...");
}

void loop() {

    // Process the hardware loop for both modules
    sds011Module->processHardwareDeviceLoop();
    sdc30Module->processHardwareDeviceLoop(); // Boucle matériel du SDC30

    // Log hardware state every 10 seconds
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        // Save the last time logs were displayed
        previousMillis = currentMillis;

        // Log hardware state for both modules
        logHardwareState(sds011Module->entitiesContainer);
        logHardwareState(sdc30Module->entitiesContainer); // Log de l'état matériel du module SDC30
    }

    delay(2000);
}

void logEntitiesContainer(EntitiesContainerInterface* container) {
    int count = container->count();
    for(int i = 0; i < count; i++) {
        EntityInterface* entity = container->getEntity(i);
        if(entity != nullptr) {
            // Convert EntityInfo to String
            EntityInfo info = entity->getInfo();
            String infoStr = String("Name: ") + info.name + "\nType: " + info.type + "\nUnique ID: " + info.unique_id;
            
            // Convert EntityState to String
            EntityState state = entity->getState();
            String stateStr = String("Should Send State Update: ") + (state.shouldSendStateUpdate ? "true" : "false") + 
                              "\nHas Lost Connection: " + (state.hasLostConnexion ? "true" : "false");

            Serial.println("Entity " + String(i) + ":");
            Serial.println("Info: " + infoStr);
            Serial.println("State: " + stateStr);
        }
    }
}

void logHardwareState(EntitiesContainerInterface* container) {
    // Loop through all entities in the container and print their hardware state
    int count = container->count();
    for(int i = 0; i < count; i++) {
        EntityInterface* entity = container->getEntity(i);
        AbstractEntityHardwareState& hardwareState = entity->getHardwareState();
        
        DynamicJsonDocument hardwareStateJson = hardwareState.getJSONHardwareState(); 
        String hardwareStateStr;
        serializeJson(hardwareStateJson, hardwareStateStr);

        Serial.println("Entity " + String(i) + " Hardware State:");
        Serial.println(hardwareStateStr);
    }
}

