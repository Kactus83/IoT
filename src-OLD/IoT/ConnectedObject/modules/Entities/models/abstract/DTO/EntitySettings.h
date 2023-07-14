#ifndef ENTITY_SETTINGS_H
#define ENTITY_SETTINGS_H

#include <Arduino.h>

class EntitySettings {
public:
    String type;
    virtual ~EntitySettings() {}
};

#endif // ENTITY_SETTINGS_H
