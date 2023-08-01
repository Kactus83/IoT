#include "IoT/implementations/common/Hardware/Sensors/SDS011/HardwareDeviceModule_SDS011.h"
#include <Arduino.h>
#include <ArduinoJson.h> // Inclure la bibliothèque pour manipuler JSON

// Define global variable
HardwareDeviceModule_SDS011* sds011Module;

// Define the interval for logs
const long interval = 60000; // 60 seconds
unsigned long previousMillis = 0;  // will store the last time logs were displayed

void setup() {
    // Initialize the module
    sds011Module = new HardwareDeviceModule_SDS011(0, 1); // Suppose that SDS011 sensor is connected to pins 0 and 1
    
    // Initialize serial communication
    Serial.begin(9600);
    while(!Serial) { } // Wait until the Serial is available

    // Get entities container from the module
    EntitiesContainerInterface* sds011Container = sds011Module->entitiesContainer;

    // Log container data during setup
    int count = sds011Container->count();
    for(int i = 0; i < count; i++) {
        EntityInterface* entity = sds011Container->getEntity(i);
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

    Serial.println("Setup completed, starting loop...");
}

void loop() {
    // ... Votre code régulier de loop ...

    // Log hardware state every 60 seconds
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        // Save the last time logs were displayed
        previousMillis = currentMillis;

        // Get entities container from the module
        EntitiesContainerInterface* sds011Container = sds011Module->entitiesContainer;

        // Loop through all entities in the container and print their hardware state
        int count = sds011Container->count();
        for(int i = 0; i < count; i++) {
            EntityInterface* entity = sds011Container->getEntity(i);
            AbstractEntityHardwareState& hardwareState = entity->getHardwareState();
            
            DynamicJsonDocument hardwareStateJson = hardwareState.getJSONHardwareState(); // Utilisez '.' au lieu de '->'
            String hardwareStateStr;
            serializeJson(hardwareStateJson, hardwareStateStr);

            Serial.println("Entity " + String(i) + " Hardware State:");
            Serial.println(hardwareStateStr);
        }
    }
}

