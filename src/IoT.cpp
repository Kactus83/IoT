#include "IoT/implementations/common/Hardware/Sensors/SDS011/HardwareDeviceModule_SDS011.h"
#include "IoT/implementations/common/Hardware/Sensors/SDC30/HardwareDeviceModule_SDC30.h" // Inclure l'entête du module SDC30
#include "IoT/abstract/Hardware/AbstractHardwareDevicesModulesContainer.h"
#include "./IoT/abstract/ConnectedObject.h"
#include <Arduino.h>
#include <ArduinoJson.h> // Inclure la bibliothèque pour manipuler JSON

// Define global variables
AbstractHardwareDevicesModulesContainer* hardwareContainer;
ConnectedObject* connectedObject;

// Define the interval for logs
const long interval = 10000; // 10 seconds
unsigned long previousMillis = 0;  // will store the last time logs were displayed

// Declare functions
void logEntitiesContainer();
void logHardwareState();

void setup() {
    // Initialize serial communication
    Serial.begin(9600); 
    while(!Serial) { } // Wait until the Serial is available

    // Define the modules array
    HardwareDeviceModuleInterface* modules[] = {
        new HardwareDeviceModule_SDS011(0, 1), // Suppose that SDS011 sensor is connected to pins 0 and 1
        new HardwareDeviceModule_SDC30() // Configuration pour le SDC30
    };

    // Instantiate the hardware container
    hardwareContainer = new AbstractHardwareDevicesModulesContainer(modules, sizeof(modules) / sizeof(modules[0]));

    // Instantiate the connected object
    connectedObject = new ConnectedObject(hardwareContainer);

    // Setup the connected object
    connectedObject->setup();

    // Optional log for initial state
    logEntitiesContainer();
    logHardwareState();

    Serial.println("Setup completed, starting loop...");
}

void loop() {
    // Process the connected object loop
    connectedObject->loop();

    // Log hardware state every 10 seconds
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        // Save the last time logs were displayed
        previousMillis = currentMillis;

        // Log hardware state
        logHardwareState();
    }

    delay(2000);
}

void logEntitiesContainer() {
    int count = hardwareContainer->totalEntityCount();
    for(int i = 0; i < count; i++) {
        EntityInterface* entity = hardwareContainer->getEntity(i);
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

void logHardwareState() {
    int count = hardwareContainer->totalEntityCount();
    for(int i = 0; i < count; i++) {
        EntityInterface* entity = hardwareContainer->getEntity(i);
        AbstractEntityHardwareState& hardwareState = entity->getHardwareState();
        
        DynamicJsonDocument hardwareStateJson = hardwareState.getJSONHardwareState(); 
        String hardwareStateStr;
        serializeJson(hardwareStateJson, hardwareStateStr);

        Serial.println("Entity " + String(i) + " Hardware State:");
        Serial.println(hardwareStateStr);
    }
}
