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
    EntityDataManager(EntityInfo& info, GenericEntityState& state, SpecificEntityState* specificState)
        : info(info), state(state), specificState(specificState), messagesManager(nullptr) {}

    virtual ~EntityDataManager() {}

    void setMessagesManager(MQTTMessagesManagerInterface& messagesManager) {
        this->messagesManager = &messagesManager;
    }

    virtual void setupEntityForHomeAssistant() {
        const char* discoveryMessage = createDiscoveryMessage();
        messagesManager->sendMQTTMessage(info.discoveryTopic, discoveryMessage);
        messagesManager->subscribeToMQTTTopic(info.setTopic);
    }

    virtual void sendState() {
        if (specificState->stateChanged) {
            DynamicJsonDocument doc(1024);
            doc["enabled"] = state.enabled;

            DynamicJsonDocument specificStateDoc = specificState->getState();
            for (JsonPair kv : specificStateDoc.as<JsonObject>()) {
                doc[kv.key()] = kv.value();
            }

            // Estimez la taille du document JSON
            size_t jsonSize = measureJson(doc);

            // Créez un tableau de char assez grand pour le document JSON
            char* output = new char[jsonSize + 1];  // +1 pour le caractère nul de fin de chaîne

            // Sérialisez le document JSON dans le tableau de char
            serializeJson(doc, output, jsonSize + 1);

            messagesManager->sendMQTTMessage(info.getTopic, output);

            specificState->stateChanged = false;

            // N'oubliez pas de libérer la mémoire une fois que vous avez fini d'utiliser le tableau de char
            delete[] output;
        }
    }

    virtual void handleIncomingMessage(const String& message) {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, message);

        if (doc.containsKey("enabled")) {
            state.enabled = doc["enabled"];
        }

        specificState->setStateFromMQTTMessage(message);
    }

protected:
    EntityInfo& info;
    GenericEntityState& state;
    SpecificEntityState* specificState;
    MQTTMessagesManagerInterface* messagesManager;

    char* createDiscoveryMessage() {
        DynamicJsonDocument doc(1024);

        doc["type"] = info.type;
        doc["unique_id"] = info.unique_id;
        doc["enabled"] = state.enabled;

        DynamicJsonDocument specificStateDoc = specificState->getState();
        for (JsonPair kv : specificStateDoc.as<JsonObject>()) {
            doc[kv.key()] = kv.value();
        }

        // Estimer la taille du document JSON
        size_t jsonSize = measureJson(doc);

        // Créer un tableau de char assez grand pour le document JSON
        char* output = new char[jsonSize + 1];  // +1 pour le caractère nul de fin de chaîne

        // Sérialiser le document JSON dans le tableau de char
        serializeJson(doc, output, jsonSize + 1);

        return output;
    }
};

#endif // ENTITYDATAMANAGER_H
