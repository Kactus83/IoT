#ifndef WS12_RGB_LED_SETTINGS_H
#define WS12_RGB_LED_SETTINGS_H

#include <Arduino.h>
#include "../../../../Entities/abstract/DTO/EntitySettings.h"

class WS12_RGB_LED_Settings : public EntitySettings {
public:
    WS12_RGB_LED_Settings(uint8_t pin, uint16_t num_leds, int8_t index) : pin(pin), num_leds(num_leds) {
        this->type = "light";
        this->name = "WS12_RGB_LED";
        this->index = new int8_t(index);
    }

    uint8_t pin;
    uint16_t num_leds;
};

#endif // WS12_RGB_LED_SETTINGS_H
