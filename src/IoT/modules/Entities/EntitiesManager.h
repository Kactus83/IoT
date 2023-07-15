#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <Arduino.h>
#include "EntitiesManagerInterface.h"
#include "./EntityFactory.h"
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "./implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Settings.h"

class EntitiesManager : public EntitiesManagerInterface, public EntityFactory {
public:
    EntitiesManager(const DeviceConfig& config) : EntityFactory(config) {}

    ~EntitiesManager() {}

    void setupEntities() override {
        Serial.println("Setting up entities...");
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->setup();
        }
    }

    void createEntities() {
        Serial.println("Creating entities...");
        WS12_RGB_LED_Settings ledSettings(6, 144);
        createWS12_RGB_LED_Entity(ledSettings);
    }

    void handleIncomingMQTTMessage(const String& topic, const String& message) override {
        Serial.println("Handling incoming MQTT message: " + message + " for topic: " + topic);
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            if(entities[entityIndex]->info.setTopic == topic){
                entities[entityIndex]->handleMQTTMessage(topic, message);
            }
        }
    }

    void handleHomeAssistantConnectionInterruption() override {
        Serial.println("Handling Home Assistant connection interruption...");
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->reconnect();
        }
    }

    void entitiesLoop() override {
        for(int entityIndex = 0; entityIndex < entityCount; entityIndex++){
            entities[entityIndex]->loop();
        }
    }

};

#endif // ENTITIESMANAGER_H
