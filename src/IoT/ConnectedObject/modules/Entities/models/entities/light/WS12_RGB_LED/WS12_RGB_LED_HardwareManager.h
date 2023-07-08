#ifndef WS12_RGB_LED_HARDWAREMANAGER_H
#define WS12_RGB_LED_HARDWAREMANAGER_H

#include <Arduino.h>
#include "../../../abstract/modules/EntityHardwareManagerInterface.h"

class WS12_RGB_LED_HardwareManager : public EntityHardwareManagerInterface {
public:
    WS12_RGB_LED_HardwareManager() {}
    virtual ~WS12_RGB_LED_HardwareManager() {}

    virtual void initHardware() override {
        // A compléter avec l'initialisation du matériel LED
    }

    virtual void processHardwareLoop() override {
        // A compléter avec la boucle de traitement du matériel LED
    }
};

#endif // WS12_RGB_LED_HARDWAREMANAGER_H