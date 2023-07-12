// IoT.cpp
#include "settings.h"
#include "./IoT/ConnectedObject/modules/Config/ConfigManager.h"
#include "./IoT/ConnectedObject/modules/Messages/MessagesManager.h"

// Initialize the ConfigManager and MessagesManager
ConfigManager configManager(factorySettings);
MessagesManager messagesManager;

void setup() {
    // Perform setup activities
    // Note: Your managers may require some setup steps.
    // If that's the case, you should add the necessary function calls here.
}

void loop() {
    // Main loop
    // Note: Your managers may require some loop steps.
    // If that's the case, you should add the necessary function calls here.
}
