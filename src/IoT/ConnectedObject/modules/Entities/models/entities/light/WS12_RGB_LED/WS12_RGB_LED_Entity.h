// WS12_RGB_LED_Entity.h
#ifndef WS12_RGB_LED_ENTITY_H
#define WS12_RGB_LED_ENTITY_H

#include <Arduino.h>
#include "../../../abstract/GenericEntity.h"
#include "WS12_RGB_LED_HardwareManager.h"
#include "WS12_RGB_LED_SpecificEntityState.h"

class WS12_RGB_LED_Entity : public GenericEntity {
public:
    WS12_RGB_LED_Entity() : GenericEntity(new WS12_RGB_LED_HardwareManager(), new WS12_RGB_LED_SpecificEntityState()) {}
    virtual ~WS12_RGB_LED_Entity() {}
};

#endif // WS12_RGB_LED_ENTITY_H
