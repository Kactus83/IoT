#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "../Config/DTO/EntitiesConfig.h"

class EntitiesManager : public EntitiesManagerInterface {
public:
    EntitiesManager(EntitiesConfig& entitiesConfig)
        : entities(entitiesConfig.entities),
          entityCount(entitiesConfig.entityCount),
          messagesManager(nullptr) {}

    ~EntitiesManager() {}

    void setMessagesManager(MQTTMessagesManagerInterface& messageManager) override {
        messagesManager = &messageManager;
    }

    void setupEntities() override {
        Serial.println("Setting up entities...");
        for (int entityIndex = 0; entityIndex < entityCount; entityIndex++) {
            if (entities[entityIndex] == nullptr) {
                Serial.println("Entity at index " + String(entityIndex) + " is null!");
            } else {
                if (messagesManager != nullptr) {
                    entities[entityIndex]->setMessageManager(*messagesManager);
                }
                entities[entityIndex]->setup();
            }
        }
    }

    void handleIncomingMQTTMessage(const String& topic, const String& message) override {
        Serial.println("Handling incoming MQTT message: " + message + " for topic: " + topic);
        for (int entityIndex = 0; entityIndex < entityCount; entityIndex++) {
            if (entities[entityIndex]->handlesTopic(topic)) {
                entities[entityIndex]->handleMQTTMessage(topic, message);
            }
        }
    }

    void handleHomeAssistantConnectionInterruption() override {
        Serial.println("Handling Home Assistant connection interruption...");
        for (int entityIndex = 0; entityIndex < entityCount; entityIndex++) {
            entities[entityIndex]->reconnect();
        }
    }

    void entitiesLoop() override {
        for (int entityIndex = 0; entityIndex < entityCount; entityIndex++) {
            entities[entityIndex]->loop();
        }
    }

private:
    GenericEntityInterface** entities;
    int entityCount;
    MQTTMessagesManagerInterface* messagesManager;
};

#endif // ENTITIESMANAGER_H
