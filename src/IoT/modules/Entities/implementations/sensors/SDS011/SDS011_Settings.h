#ifndef SDS011_SETTINGS_H
#define SDS011_SETTINGS_H

#include <Arduino.h>
#include "../../../../Entities/abstract/DTO/EntitySettings.h"

class SDS011_Settings : public EntitySettings {
public:
    SDS011_Settings(uint8_t pin_RX, uint8_t pin_TX, int8_t index) : pin_RX(pin_RX), pin_TX(pin_TX) {
        this->type = "air_quality";
        this->name = "SDS011";
        this->index = new int8_t(index);
    }

    uint8_t pin_RX;
    uint8_t pin_TX;
};

#endif // SDS011_SETTINGS_H
