#ifndef WS12_RGB_LED_HARDWAREMANAGER_H
#define WS12_RGB_LED_HARDWAREMANAGER_H

#include <Arduino.h>
#include "../../../abstract/modules/EntityHardwareManagerInterface.h"
#include "../../EntitySettings.h"
#include "WS12_RGB_LED_Settings.h"

class WS12_RGB_LED_HardwareManager : public EntityHardwareManagerInterface {
public:
    WS12_RGB_LED_HardwareManager(const WS12_RGB_LED_Settings& settings) : pin(settings.pin), num_leds(settings.num_leds) {}

    virtual void initHardware() override {
        // A compléter avec l'initialisation du matériel LED
    }

    virtual void processHardwareLoop() override {
        // A compléter avec la boucle de traitement du matériel LED
    }

private:
    uint8_t pin;
    uint16_t num_leds;
};

#endif // WS12_RGB_LED_HARDWAREMANAGER_H
