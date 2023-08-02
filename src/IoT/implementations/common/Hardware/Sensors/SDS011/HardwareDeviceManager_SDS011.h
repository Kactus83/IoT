#ifndef HARDWARE_DEVICE_MANAGER_SDS011_H
#define HARDWARE_DEVICE_MANAGER_SDS011_H

#include <SDS011.h>
#include "EntitiesContainer_SDS011.h"
#include "../../../../../abstract/Hardware/HardwareDeviceManagerInterface.h"

class HardwareDeviceManager_SDS011 : public HardwareDeviceManagerInterface
{
public:
    HardwareDeviceManager_SDS011(EntitiesContainer_SDS011* entitiesContainer, int rxPin, int txPin)
        : entitiesContainer_(entitiesContainer), rxPin_(rxPin), txPin_(txPin)
    {
        my_sds.begin(rxPin_, txPin_);
    }

    void setupHardware() override
    {
        // Setup the sensor with the rxPin and txPin
    }

    void processHardwareLoop() override
    {
        float p25, p10;
        int error = my_sds.read(&p25, &p10);

        if (!error) {
            // Utilisation de la méthode getSpecificHardwareState
            entitiesContainer_->pm10Sensor.getSpecificHardwareState().pm10 = p10;
            entitiesContainer_->pm2_5Sensor.getSpecificHardwareState().pm2_5 = p25;
        } else {
            Serial.println("Error reading from SDS011!");
        }
    }

private:
    EntitiesContainer_SDS011* entitiesContainer_;
    int rxPin_;
    int txPin_;
    SDS011 my_sds; // SDS011 instance
};

#endif // HARDWARE_DEVICE_MANAGER_SDS011_H
