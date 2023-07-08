#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <Arduino.h>
#include "./abstract/GenericEntityInterface.h"
#include "../Config/DTO/DeviceConfig.h"
#include "../Messages/MessagesManagerInterface.h"

class EntityFactory {
public:
    EntityFactory(const DeviceConfig& config, MessagesManagerInterface& messagesManager) 
    : config(config), messagesManager(messagesManager) {}

    void setupEntityTopics(GenericEntityInterface& entity) const {
        entity.info.discoveryTopic = config.INTEGRATION_NAME + "/discovery";
        entity.info.getTopic = config.INTEGRATION_NAME + "/" + entity.info.type + "/" + entity.info.unique_id + "/get";
        entity.info.setTopic = config.INTEGRATION_NAME + "/" + entity.info.type + "/" + entity.info.unique_id + "/set";
    }

protected:
    DeviceConfig config;
    MessagesManagerInterface& messagesManager;
};

#endif // ENTITYFACTORY_H
