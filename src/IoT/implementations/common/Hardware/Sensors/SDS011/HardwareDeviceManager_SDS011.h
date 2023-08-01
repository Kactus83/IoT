#ifndef HARDWARE_DEVICE_MANAGER_SDS011_H
#define HARDWARE_DEVICE_MANAGER_SDS011_H

#include "../../../../../abstract/Hardware/HardwareDeviceManagerInterface.h"
#include "../../../../../abstract/Entity/EntitiesContainerInterface.h"

class HardwareDeviceManager_SDS011 : public HardwareDeviceManagerInterface
{
public:
    HardwareDeviceManager_SDS011(EntitiesContainerInterface* entitiesContainer, int rxPin, int txPin)
        : entitiesContainer_(entitiesContainer), rxPin_(rxPin), txPin_(txPin)
    {
    }

    void setupHardware() override
    {
        // Setup the sensor with the rxPin and txPin
    }

    void processHardwareLoop() override
    {
        // Process the sensor data and update the entities in the container
    }

private:
    EntitiesContainerInterface* entitiesContainer_;
    int rxPin_;
    int txPin_;
};

#endif // HARDWARE_DEVICE_MANAGER_SDS011_H
