#ifndef HARDWARE_DEVICE_MANAGER_SDC30_H
#define HARDWARE_DEVICE_MANAGER_SDC30_H

#include <Adafruit_SCD30.h>
#include "EntitiesContainer_SDC30.h"
#include "../../../../../abstract/Hardware/HardwareDeviceManagerInterface.h"

class HardwareDeviceManager_SDC30 : public HardwareDeviceManagerInterface
{
public:
    HardwareDeviceManager_SDC30(EntitiesContainer_SDC30* entitiesContainer)
        : entitiesContainer_(entitiesContainer)
    {
        if (!scd30.begin()) {
            Serial.println("Failed to find SCD30 chip");
        }
    }

    void setupHardware() override
    {
        // Possible additional setup
    }

    void processHardwareLoop() override
    {
        if (scd30.dataReady()) {
            if (!scd30.read()) {
                Serial.println("Error reading sensor data");
                return;
            }

            entitiesContainer_->temperatureSensor.getSpecificHardwareState().temperature = scd30.temperature;
            entitiesContainer_->co2Sensor.getSpecificHardwareState().CO2 = scd30.CO2;
            entitiesContainer_->humiditySensor.getSpecificHardwareState().humidity = scd30.relative_humidity;
        }
    }

private:
    EntitiesContainer_SDC30* entitiesContainer_;
    Adafruit_SCD30 scd30; // SDC30 instance
};

#endif // HARDWARE_DEVICE_MANAGER_SDC30_H
