#ifndef ENTITYDATAMANAGER_H
#define ENTITYDATAMANAGER_H

#include <Arduino.h>
#include "../DTO/EntityInfo.h"
#include "../DTO/GenericEntityState.h"
#include "../DTO/SpecificEntityState.h"
#include "../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include <ArduinoJson.h>

class EntityDataManager {
public:
    EntityDataManager(EntityInfo& info, GenericEntityState& state, SpecificEntityState* specificState, MQTTMessagesManagerInterface& messagesManager)
        : info(info), state(state), specificState(specificState), messagesManager(messagesManager) {}

    virtual ~EntityDataManager() {}

    virtual void setupEntityForHomeAssistant() {
        String discoveryMessage = createDiscoveryMessage();
        messagesManager.sendMQTTMessage(info.discoveryTopic, discoveryMessage);
        messagesManager.subscribeToMQTTTopic(info.setTopic);
    }

    virtual void sendState() {
        DynamicJsonDocument doc(1024);
        doc["enabled"] = state.enabled;

        DynamicJsonDocument specificStateDoc = specificState->getState();
        for(JsonPair kv : specificStateDoc.as<JsonObject>()) {
            doc[kv.key()] = kv.value();
        }

        String output;
        serializeJson(doc, output);
        messagesManager.sendMQTTMessage(info.getTopic, output);
    }

    virtual void handleIncomingMessage(const String& message) {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, message);

        if(doc.containsKey("enabled")) {
            state.enabled = doc["enabled"];
        }

        specificState->setStateFromMQTTMessage(message);
    }

protected:
    EntityInfo& info;
    GenericEntityState& state;
    SpecificEntityState* specificState;
    MQTTMessagesManagerInterface& messagesManager;

    String createDiscoveryMessage() {
        DynamicJsonDocument doc(1024);

        doc["type"] = info.type;
        doc["unique_id"] = info.unique_id;
        doc["enabled"] = state.enabled;

        DynamicJsonDocument specificStateDoc = specificState->getState();
        for(JsonPair kv : specificStateDoc.as<JsonObject>()) {
            doc[kv.key()] = kv.value();
        }

        String output;
        serializeJson(doc, output);

        return output;
    }
};

#endif // ENTITYDATAMANAGER_H
