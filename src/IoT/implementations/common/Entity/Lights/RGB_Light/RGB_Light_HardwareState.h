#ifndef RGB_LIGHT_HARDWARE_STATE_H
#define RGB_LIGHT_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class RGB_Light_HardwareState : public AbstractEntityHardwareState
{
public:
    int brightness = 0;
    int color_temp = 0;
    int rgbww_color[5] = {0, 0, 0, 0, 0};
    char effect[20];
    char effect_list[10][20];

    virtual DynamicJsonDocument getJSONHardwareState() override {
        DynamicJsonDocument doc(1024);
        doc["brightness"] = brightness;
        doc["color_temp"] = color_temp;
        for(int i = 0; i < 5; i++) {
            doc["rgbww_color"][i] = rgbww_color[i];
        }
        doc["effect"] = effect;
        return doc;
    }

    virtual void setHardwareStateFromJSON(const String& json) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        brightness = doc["brightness"];
        color_temp = doc["color_temp"];
        for(int i = 0; i < 5; i++) {
            rgbww_color[i] = doc["rgbww_color"][i];
        }
        strlcpy(effect, doc["effect"], sizeof(effect));
    }
};

#endif // RGB_LIGHT_HARDWARE_STATE_H
