#ifndef HARDWARE_DEVICE_MODULE_INTERFACE_H
#define HARDWARE_DEVICE_MODULE_INTERFACE_H

#include "../Entity/EntitiesContainerInterface.h"

class HardwareDeviceModuleInterface
{
public:
    virtual ~HardwareDeviceModuleInterface() {}

    EntitiesContainerInterface* entitiesContainer;

    virtual void setupHardwareDevice() = 0;
    virtual void processHardwareDeviceLoop() = 0;
};


#endif // HARDWARE_DEVICE_MODULE_INTERFACE_H
