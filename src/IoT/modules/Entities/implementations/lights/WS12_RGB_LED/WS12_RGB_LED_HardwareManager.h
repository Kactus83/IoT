 #ifndef WS12_RGB_LED_HARDWAREMANAGER_H
 #define WS12_RGB_LED_HARDWAREMANAGER_H

 #include <Arduino.h>
 #include "../../../../Entities/abstract/modules/Abstract_EntityHardwareManager.h"
 #include "WS12_RGB_LED_Settings.h"
 #include "WS12_RGB_LED_SpecificEntityState.h"

 class WS12_RGB_LED_HardwareManager : public Abstract_EntityHardwareManager<WS12_RGB_LED_SpecificEntityState, WS12_RGB_LED_Settings> {
 public:
     WS12_RGB_LED_HardwareManager(WS12_RGB_LED_SpecificEntityState& state, WS12_RGB_LED_Settings& settings)
         : Abstract_EntityHardwareManager<WS12_RGB_LED_SpecificEntityState, WS12_RGB_LED_Settings>(state, settings) {}

     virtual void initHardware() override {
         // A compléter avec l'initialisation du matériel LED
     }

     virtual void processHardwareLoop() override {
         // A compléter avec la boucle de traitement du matériel LED
     }
 };

 #endif // WS12_RGB_LED_HARDWAREMANAGER_H
