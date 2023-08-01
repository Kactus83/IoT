#ifndef HARDWARE_DEVICE_MANAGER_INTERFACE_H
#define HARDWARE_DEVICE_MANAGER_INTERFACE_H

class HardwareDeviceManagerInterface
{
public:
    virtual ~HardwareDeviceManagerInterface() {}

    // Virtual methods that should be overridden in the derived classes.
    virtual void setupHardware() = 0;
    virtual void processHardwareLoop() = 0;
};

#endif // HARDWARE_DEVICE_MANAGER_INTERFACE_H
