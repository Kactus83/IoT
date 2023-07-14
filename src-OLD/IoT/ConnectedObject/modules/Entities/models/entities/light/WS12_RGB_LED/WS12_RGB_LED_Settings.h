#ifndef WS12_RGB_LED_SETTINGS_H
#define WS12_RGB_LED_SETTINGS_H

#include <Arduino.h>
#include "../../../abstract/DTO/EntitySettings.h"

class WS12_RGB_LED_Settings : public EntitySettings {
public:
    WS12_RGB_LED_Settings(uint8_t pin, uint16_t num_leds) : pin(pin), num_leds(num_leds) {
        this->type = "light";
    }

    uint8_t pin;
    uint16_t num_leds;
};

#endif // WS12_RGB_LED_SETTINGS_H
