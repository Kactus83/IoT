 #ifndef WS12_RGB_LED_ENTITY_H
 #define WS12_RGB_LED_ENTITY_H

 #include <Arduino.h>
 #include "../../../../Entities/abstract/GenericEntity.h"
 #include "../../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"
 #include "WS12_RGB_LED_HardwareManager.h"
 #include "WS12_RGB_LED_SpecificEntityState.h"
 #include "WS12_RGB_LED_Settings.h"

 class WS12_RGB_LED_Entity : public GenericEntity<WS12_RGB_LED_HardwareManager, WS12_RGB_LED_SpecificEntityState, WS12_RGB_LED_Settings> {
 public:
     WS12_RGB_LED_Entity(EntityInfo& info, MQTTMessagesManagerInterface& messagesManager, WS12_RGB_LED_Settings& settings)
         : GenericEntity<WS12_RGB_LED_HardwareManager, WS12_RGB_LED_SpecificEntityState, WS12_RGB_LED_Settings>(info, settings, messagesManager) {}
 };

 #endif // WS12_RGB_LED_ENTITY_H
