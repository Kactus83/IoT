#ifndef ENTITYINFO_H
#define ENTITYINFO_H

#include <Arduino.h>

struct EntityInfo {
    const char* type;
    const char* unique_id;
    const char* discoveryTopic;
    const char* getTopic;
    const char* setTopic;
};

#endif // ENTITYINFO_H
