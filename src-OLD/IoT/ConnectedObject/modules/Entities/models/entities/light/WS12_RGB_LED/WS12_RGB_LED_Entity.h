#ifndef WS12_RGB_LED_ENTITY_H
#define WS12_RGB_LED_ENTITY_H

#include <Arduino.h>
#include "../../../abstract/GenericEntity.h"
#include "WS12_RGB_LED_HardwareManager.h"
#include "WS12_RGB_LED_SpecificEntityState.h"
#include "../../../abstract/DTO/EntitySettings.h"
#include "WS12_RGB_LED_Settings.h"

class WS12_RGB_LED_Entity : public GenericEntity<WS12_RGB_LED_HardwareManager, WS12_RGB_LED_SpecificEntityState> {
public:
    WS12_RGB_LED_Entity(EntityInfo& info, MessagesManagerInterface& messagesManager, const WS12_RGB_LED_Settings& settings)
        : GenericEntity<WS12_RGB_LED_HardwareManager, WS12_RGB_LED_SpecificEntityState>(info, messagesManager), hardwareManager(settings) {}

    virtual ~WS12_RGB_LED_Entity() {}

private:
    WS12_RGB_LED_HardwareManager hardwareManager;
};

#endif // WS12_RGB_LED_ENTITY_H
