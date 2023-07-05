#ifndef ENTITYINFO_H
#define ENTITYINFO_H

#include <Arduino.h>

struct EntityInfo {
    String type;
    String unique_id;
    String MQTT_PostTopic;
    String MQTT_GetTopic;
};

#endif // ENTITYINFO_H
