#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "./EntityFactory.h"
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "./abstract/DTO/EntitySettings.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class EntitiesManager : public EntitiesManagerInterface, public EntityFactory {
public:
    EntitiesManager(const DeviceConfig& config) : EntityFactory(config) {
        maxEntities = config.MAX_ENTITIES;
        entities = new GenericEntityInterface*[maxEntities]; 
    }

    ~EntitiesManager() {
        delete[] entities;
    }

    // Ces méthodes sont vides pour l'instant
    void handleIncomingMQTTMessage(const String& topic, const String& message) override {}

    void handleHomeAssistantConnectionInterruption() override {}

    void addEntity(EntitySettings& settings) {
        // Ne fait rien pour le moment
    }

private:
    GenericEntityInterface** entities;
    int maxEntities;
};

#endif // ENTITIESMANAGER_H
