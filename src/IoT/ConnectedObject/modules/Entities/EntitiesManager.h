#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "./abstract/GenericEntityInterface.h"
#include "../Config/DTO/DeviceConfig.h"

class EntitiesManager : public EntitiesManagerInterface {
public:
    EntitiesManager(const DeviceConfig& config)
    : maxEntities(config.MAX_ENTITIES), entityCount(0) {}

    void setupEntities() override {
        for(int i = 0; i < entityCount; i++){
            entities[i]->setup();
        }
    }

    void handleHomeAssistantConnectionInterruption() override {
        for(int i = 0; i < entityCount; i++){
            entities[i]->reconnect();
        }
    }

    void handleMQTTMessage(const String& topic, const String& message) override {
    // Method left unimplemented as per your request
    }

    void entitiesLoop() override {
        for(int i = 0; i < entityCount; i++){
            entities[i]->loop();
        }
    }

    bool addEntity(GenericEntityInterface* entity){
        if(entityCount < maxEntities){
            entities[entityCount] = entity;
            entityCount++;
            return true;
        } else {
            return false;
        }
    }

private:
    GenericEntityInterface* entities[maxEntities];
    int entityCount;
    int maxEntities;
};

#endif // ENTITIESMANAGER_H
