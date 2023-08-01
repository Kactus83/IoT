#ifndef HARDWARE_DEVICE_MODULE_SDS011_H
#define HARDWARE_DEVICE_MODULE_SDS011_H

#include "../../../../../abstract/Hardware/AbstractHardwareDeviceModule.h"
#include "HardwareDeviceManager_SDS011.h"
#include "EntitiesContainer_SDS011.h"

class HardwareDeviceModule_SDS011 : public AbstractHardwareDeviceModule
{
public:
    HardwareDeviceModule_SDS011(int rxPin, int txPin)
        : entitiesContainer_sds011("SDS011"),
          hardwareDeviceManager_sds011(&entitiesContainer_sds011, rxPin, txPin),
          AbstractHardwareDeviceModule(&entitiesContainer_sds011, &hardwareDeviceManager_sds011)
    {
    }

    void setupHardwareDevice() override
    {
        hardwareManager->setupHardware(); 
    }

    void processHardwareDeviceLoop() override
    {
        hardwareManager->processHardwareLoop(); 
    }

private:
    HardwareDeviceManager_SDS011 hardwareDeviceManager_sds011;
    EntitiesContainer_SDS011 entitiesContainer_sds011;
};



#endif // HARDWARE_DEVICE_MODULE_SDS011_H