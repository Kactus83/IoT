#ifndef ENTITY_SETTINGS_H
#define ENTITY_SETTINGS_H

#include <Arduino.h>

class EntitySettings {
public:
    const char* type;
    int8_t* index;
    virtual ~EntitySettings() {}
};

#endif // ENTITY_SETTINGS_H
