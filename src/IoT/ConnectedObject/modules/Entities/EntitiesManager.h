#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "./EntityFactory.h"
#include "./models/abstract/GenericEntityInterface.h"
#include "../Messages/MessagesManagerInterface.h"
#include "../Config/DTO/DeviceConfig.h"

class EntitiesManager : public EntitiesManagerInterface, public EntityFactory {
public:
    EntitiesManager(const DeviceConfig& config, MessagesManagerInterface& messagesManager)
    : EntityFactory(config, messagesManager), maxEntities(config.MAX_ENTITIES), entityCount(0) {
        entities = new GenericEntityInterface*[maxEntities]; 
    }

    ~EntitiesManager() {
        delete[] entities;
    }

    void setupEntities() override {
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->setup();
        }
    }

    void handleHomeAssistantConnectionInterruption() override {
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->reconnect();
        }
    }

    void handleMQTTMessage(const String& topic, const String& message) override {
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            if(entities[entityIndex]->info.setTopic == topic){
                entities[entityIndex]->handleMQTTMessage(topic, message);
            }
        }
    }

    void entitiesLoop() override {
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->loop();
        }
    }
    
    void addEntity(EntitySettings& settings) {
        if (entityCount < maxEntities) {
            GenericEntityInterface* newEntity = createEntity(settings);
            if(newEntity != nullptr){
                entities[entityCount++] = newEntity;
            }
        }
    }

private:
    GenericEntityInterface** entities;
    int entityCount;
    int maxEntities;
};

#endif // ENTITIESMANAGER_H