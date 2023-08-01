#include "IoT/implementations/common/Hardware/Sensors/SDS011/Entities_Container_SDS011.h"
#include <Arduino.h>

// Define global variable
Entities_Container_SDS011* sds011Container;

// Define the interval for logs
const long interval = 10000; // 10 seconds
unsigned long previousMillis = 0;  // will store the last time logs were displayed

void setup() {
    // Initialize the container
    sds011Container = new Entities_Container_SDS011("SDS011_Base_Id");
    
    // Initialize serial communication
    Serial.begin(9600);
    while(!Serial) { } // Wait until the Serial is available
    Serial.println("Setup completed, starting loop...");
}

void loop() {
    // ... Your regular loop code ...

    // Log container data every 10 seconds
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
        // Save the last time logs were displayed
        previousMillis = currentMillis;

        // Loop through all entities in the container and print their info
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
    }
}

