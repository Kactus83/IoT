#ifndef ABSTRACT_HARDWARE_DEVICE_MODULE_H
#define ABSTRACT_HARDWARE_DEVICE_MODULE_H

#include "HardwareDeviceModuleInterface.h"
#include "HardwareDeviceManagerInterface.h"
#include "../Entity/EntitiesContainerInterface.h"

class AbstractHardwareDeviceModule : public HardwareDeviceModuleInterface
{
public:
    AbstractHardwareDeviceModule(EntitiesContainerInterface* container, HardwareDeviceManagerInterface* manager)
    {
        entitiesContainer = container;  
        hardwareManager = manager;
    }

protected:
    HardwareDeviceManagerInterface* hardwareManager;
};

#endif // ABSTRACT_HARDWARE_DEVICE_MODULE_H
