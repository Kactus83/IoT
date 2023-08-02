#ifndef HARDWARE_DEVICE_MODULE_SDC30_H
#define HARDWARE_DEVICE_MODULE_SDC30_H

#include "../../../../../abstract/Hardware/AbstractHardwareDeviceModule.h"
#include "HardwareDeviceManager_SDC30.h"
#include "EntitiesContainer_SDC30.h"

class HardwareDeviceModule_SDC30 : public AbstractHardwareDeviceModule
{
public:
    HardwareDeviceModule_SDC30()
        : entitiesContainer_sdc30("SDC30"),
          hardwareDeviceManager_sdc30(&entitiesContainer_sdc30),
          AbstractHardwareDeviceModule(&entitiesContainer_sdc30, &hardwareDeviceManager_sdc30)
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
    HardwareDeviceManager_SDC30 hardwareDeviceManager_sdc30;
    EntitiesContainer_SDC30 entitiesContainer_sdc30;
};

#endif // HARDWARE_DEVICE_MODULE_SDC30_H
