#ifndef ABSTRACT_HARDWARE_DEVICES_MODULES_CONTAINER_H
#define ABSTRACT_HARDWARE_DEVICES_MODULES_CONTAINER_H

#include "HardwareDevicesModulesContainerInterface.h"
#include "HardwareDeviceModuleInterface.h"

class AbstractHardwareDevicesModulesContainer : public HardwareDevicesModulesContainerInterface
{
public:
    AbstractHardwareDevicesModulesContainer(HardwareDeviceModuleInterface** modules, int size)
        : modules_(modules), size_(size)
    {
    }

    int moduleCount() const override
    {
        return size_;
    }

    HardwareDeviceModuleInterface* getModule(int index) override
    {
        if (index >= 0 && index < size_)
            return modules_[index];
        // should include error handling for out-of-range index
        return nullptr;
    }

    int totalEntityCount() const override
    {
        int total = 0;
        for (int i = 0; i < size_; ++i)
        {
            total += modules_[i]->entitiesContainer->count();
        }
        return total;
    }

    EntityInterface* getEntity(int globalIndex) override
    {
        int currentIndex = 0;
        for (int i = 0; i < size_; ++i)
        {
            int count = modules_[i]->entitiesContainer->count();
            if (globalIndex < currentIndex + count)
            {
                return modules_[i]->entitiesContainer->getEntity(globalIndex - currentIndex);
            }
            currentIndex += count;
        }
        // should include error handling for out-of-range index
        return nullptr;
    }

    void setupModules() override
    {
        for (int i = 0; i < size_; ++i)
        {
            modules_[i]->setupHardwareDevice();
        }
    }

    void loopModules() override
    {
        for (int i = 0; i < size_; ++i)
        {
            modules_[i]->processHardwareDeviceLoop();
        }
    }

protected:
    HardwareDeviceModuleInterface** modules_;
    int size_;
};

#endif // ABSTRACT_HARDWARE_DEVICES_MODULES_CONTAINER_H
