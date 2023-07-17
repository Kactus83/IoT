#ifndef MICS_4514_SETTINGS_H
#define MICS_4514_SETTINGS_H

#include <Arduino.h>
#include "../../../../Entities/abstract/DTO/EntitySettings.h"

class MICS_4514_Settings : public EntitySettings {
public:
    MICS_4514_Settings(uint8_t pin_NO2, uint8_t pin_CO, int8_t index) : pin_NO2(pin_NO2), pin_CO(pin_CO) {
        this->type = "air_quality";
        this->name = "MICS_4514";
        this->index = new int8_t(index);
    }

    uint8_t pin_NO2;
    uint8_t pin_CO;
};

#endif // MICS_4514_SETTINGS_H
