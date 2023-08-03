#pragma once

#include "./IoT/abstract/Hardware/HardwareDevicesModulesContainerInterface.h"

class ConnectedObject
{
public:
    ConnectedObject(HardwareDevicesModulesContainerInterface* hardwareContainer);
    void setup();
    void loop();
    HardwareDevicesModulesContainerInterface* hardwareContainer;

};
