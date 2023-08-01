#ifndef SCD30_SETTINGS_H
#define SCD30_SETTINGS_H

#include <Arduino.h>
#include "../../../../Entities/abstract/DTO/EntitySettings.h"

class SCD30_Settings : public EntitySettings {
public:
    SCD30_Settings(int8_t index) {
        this->type = "SCD30";
        this->name = "SCD30";
        this->index = new int8_t(index);
    }
};

#endif // SCD30_SETTINGS_H
