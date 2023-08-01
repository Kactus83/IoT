
#ifndef RGB_LIGHT_ENTITY_H
#define RGB_LIGHT_ENTITY_H

#include "RGB_Light_HardwareState.h"
#include "../../../../../abstract/Entity/AbstractEntity.h"

class RGB_Light_Entity : public AbstractEntity<RGB_Light_HardwareState>
{
public:
    RGB_Light_Entity(const char* unique_id)
    : AbstractEntity<RGB_Light_HardwareState>("RGB Light", "light", unique_id) {}
};

#endif // RGB_LIGHT_ENTITY_H