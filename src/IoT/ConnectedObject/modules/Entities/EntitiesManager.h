#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "./abstract/GenericEntityInterface.h"

#define MAX_ENTITIES 10 // Maximum number of entities

class EntitiesManager : public EntitiesManagerInterface {
public:
    EntitiesManager()
    : entityCount(0) {}

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
        if(entityCount < MAX_ENTITIES){
            entities[entityCount] = entity;
            entityCount++;
            return true;
        } else {
            return false;
        }
    }

private:
    GenericEntityInterface* entities[MAX_ENTITIES];
    int entityCount;
};

#endif // ENTITIESMANAGER_H
