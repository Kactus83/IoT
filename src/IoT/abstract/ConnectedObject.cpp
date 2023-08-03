#include "ConnectedObject.h"

ConnectedObject::ConnectedObject(HardwareDevicesModulesContainerInterface* hardwareContainer)
    : hardwareContainer(hardwareContainer) {}

void ConnectedObject::setup() {
    hardwareContainer->setupModules();
}

void ConnectedObject::loop() {
    hardwareContainer->loopModules();
}
