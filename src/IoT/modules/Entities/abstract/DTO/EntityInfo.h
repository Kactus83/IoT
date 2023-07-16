#ifndef ENTITYINFO_H
#define ENTITYINFO_H

#include <Arduino.h>
#include "../../../Config/DTO/DeviceConfig.h"
#include "./EntitySettings.h"

struct EntityInfo {
    const char* type;
    const char* unique_id;
    const char* discoveryTopic;
    const char* getTopic;
    const char* setTopic;

    EntityInfo(const DeviceConfig& config, const EntitySettings& settings)
    {
        this->type = strdup(settings.type);
        this->unique_id = generateUniqueID(config, settings);

        char buffer[128];

        snprintf(buffer, sizeof(buffer), "%s/discovery", config.INTEGRATION_NAME);
        this->discoveryTopic = strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%s/%s/%s/get", config.INTEGRATION_NAME, settings.type, this->unique_id);
        this->getTopic = strdup(buffer);

        snprintf(buffer, sizeof(buffer), "%s/%s/%s/set", config.INTEGRATION_NAME, settings.type, this->unique_id);
        this->setTopic = strdup(buffer);
    }

    ~EntityInfo()
    {
        free((void*)type);
        free((void*)unique_id);
        free((void*)discoveryTopic);
        free((void*)getTopic);
        free((void*)setTopic);
    }

    char* generateUniqueID(const DeviceConfig& config, const EntitySettings& settings)
    {
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "%s_%s_%d", config.INTEGRATION_NAME, settings.type, *settings.index);
        return strdup(buffer);
    }
};

#endif // ENTITYINFO_H
