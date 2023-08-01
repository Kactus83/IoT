#ifndef RGB_LIGHT_HARDWARE_STATE_H
#define RGB_LIGHT_HARDWARE_STATE_H

#include "../../../../../abstract/Entity/DTO/AbstractEntityHardwareState.h"

class RGB_Light_HardwareState : public AbstractEntityHardwareState
{
public:
    int brightness = 0;
    int color_temp = 0;
    int rgbww_color[5] = {0, 0, 0, 0, 0}; // array to hold the RGBWW color
    char effect[20]; // buffer to hold the current effect
    char effect_list[10][20]; // array to hold the list of supported effects
};

#endif // RGB_LIGHT_HARDWARE_STATE_H
