#include "IoT/objects_implementations/ConnectedObject_ArduinoUno_NoStorage.h"

// Définissez ici vos configurations de device et de hardware
DeviceConfig deviceConfig = {
    .DEVICE_NAME = "Your_Device_Name",
    .DEVICE_UNIQUE_ID = "Your_Device_Unique_ID",
    .INTEGRATION_NAME = "Your_Integration_Name",
    .STANDALONE_PASSWORD = "Your_Standalone_Password"
};

HardwareConfig hardwareConfig = {
    // Remplissez cette structure avec votre configuration matérielle
};

// Instancier un objet connecté Arduino Uno sans stockage
ConnectedObject_ArduinoUno_NoStorage<DeviceConfig, HardwareConfig> myConnectedObject;

void setup() {
    // Appel à la méthode setup de l'objet connecté
    myConnectedObject.setup();
}

void loop() {
    // Appel à la méthode loop de l'objet connecté
    myConnectedObject.loop();
}
