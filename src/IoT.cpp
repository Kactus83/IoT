// IoT.cpp
#include "settings.h"
#include "./IoT/ConnectedObject/implementations/ArduinoUno/ConnectedObject_ArduinoUno.h"

// Initialize the connected object for Arduino Uno
ConnectedObject_ArduinoUno connectedObject(factorySettings);

void setup() {
    // Perform setup activities
    connectedObject.setup();
}

void loop() {
    // Main loop
    connectedObject.loop();
}
