 #ifndef WS12_RGB_LED_SPECIFICENTITYSTATE_H
 #define WS12_RGB_LED_SPECIFICENTITYSTATE_H

 #include <Arduino.h>
 #include <ArduinoJson.h>
 #include "../../../../Entities/abstract/DTO/SpecificEntityState.h"

 class WS12_RGB_LED_SpecificEntityState : public SpecificEntityState {
 public:
     WS12_RGB_LED_SpecificEntityState() : on(false), brightness(0), hue(0), saturation(0) {}

     virtual DynamicJsonDocument getState() override {
         DynamicJsonDocument doc(1024);
         doc["state"] = on ? "ON" : "OFF";
         doc["brightness"] = brightness;
         doc["hs_color"][0] = hue;
         doc["hs_color"][1] = saturation;
         return doc;
     }

     virtual void setStateFromMQTTMessage(String message) override {
         DynamicJsonDocument doc(1024);
         deserializeJson(doc, message);
         if (doc.containsKey("state")) {
             on = doc["state"] == "ON";
         }
         if (doc.containsKey("brightness")) {
             brightness = doc["brightness"];
         }
         if (doc.containsKey("hs_color")) {
             hue = doc["hs_color"][0];
             saturation = doc["hs_color"][1];
         }
     }

 private:
     bool on;
     int brightness;
     int hue;
     int saturation;
 };

 #endif // WS12_RGB_LED_SPECIFICENTITYSTATE_H
