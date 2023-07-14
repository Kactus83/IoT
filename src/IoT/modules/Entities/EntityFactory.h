#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <Arduino.h>
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "./abstract/DTO/EntitySettings.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class EntityFactory {
public:
    EntityFactory(const DeviceConfig& config) : config(config) {}

    void setMessagesManager(MQTTMessagesManagerInterface& manager) {
        messagesManager = &manager;
    }

    // La méthode de création d'entité renvoie toujours nullptr
    GenericEntityInterface* createEntity(const EntitySettings& settings) {
        return nullptr;
    }

protected:
    DeviceConfig config;
    MQTTMessagesManagerInterface* messagesManager = nullptr;
    int entityCount = 0;
    int maxEntities;
};

#endif // ENTITYFACTORY_H
