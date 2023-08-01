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
            bool newOn = doc["state"] == "ON";
            if(on != newOn) {
                on = newOn;
                stateChanged = true;
            }
        }
        if (doc.containsKey("brightness")) {
            int newBrightness = doc["brightness"];
            if(brightness != newBrightness) {
                brightness = newBrightness;
                stateChanged = true;
            }
        }
        if (doc.containsKey("hs_color")) {
            int newHue = doc["hs_color"][0];
            int newSaturation = doc["hs_color"][1];
            if(hue != newHue || saturation != newSaturation) {
                hue = newHue;
                saturation = newSaturation;
                stateChanged = true;
            }
        }
    }

private:
    bool on;
    int brightness;
    int hue;
    int saturation;
};

#endif // WS12_RGB_LED_SPECIFICENTITYSTATE_H