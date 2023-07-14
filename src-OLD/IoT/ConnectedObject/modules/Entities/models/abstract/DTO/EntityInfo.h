#ifndef ENTITYINFO_H
#define ENTITYINFO_H

#include <Arduino.h>

struct EntityInfo {
    String type;
    String unique_id;
    String discoveryTopic;
    String getTopic;
    String setTopic;
};

#endif // ENTITYINFO_H
