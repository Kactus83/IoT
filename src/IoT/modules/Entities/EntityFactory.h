#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <Arduino.h>
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "./implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Settings.h"
#include "./implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Entity.h"

class EntityFactory {
public:
    EntityFactory(const DeviceConfig& config) : config(config), maxEntities(config.MAX_ENTITIES) {
        entities = new GenericEntityInterface*[maxEntities]; 
    }

    ~EntityFactory() {
        delete[] entities;
    }

    void setMessagesManager(MQTTMessagesManagerInterface& manager) {
        messagesManager = &manager;
    }

protected:
    DeviceConfig config;
    MQTTMessagesManagerInterface* messagesManager = nullptr;
    GenericEntityInterface** entities;
    int entityCount = 0;
    int maxEntities;

    GenericEntityInterface* createWS12_RGB_LED_Entity(const WS12_RGB_LED_Settings& settings) {
        if (!checkEntitiesCount())
            return nullptr;

        EntityInfo info;
        info.type = "led_rgb";
        info.unique_id = generateUniqueID(info.type);
        info.discoveryTopic = getDiscoveryTopic();
        info.getTopic = getGetTopic(info.type, info.unique_id);
        info.setTopic = getSetTopic(info.type, info.unique_id);

        GenericEntityInterface* newEntity = new WS12_RGB_LED_Entity(info, *messagesManager, settings);

        entities[entityCount++] = newEntity;
        
        return newEntity;
    }

    // Ajoutez d'autres méthodes de création d'entités ici pour chaque nouveau type d'entité

private:
    bool checkEntitiesCount() {
        if (entityCount >= maxEntities) {
            return false;
        }
        return true;
    }

    const char* generateUniqueID(const char* type) {
        int bufferSize = strlen(config.DEVICE_NAME) + strlen(type) + sizeof(entityCount) + 3;
        char* uniqueID = new char[bufferSize];
        sprintf(uniqueID, "%s_%s_%d", config.DEVICE_NAME, type, entityCount);
        return uniqueID;
    }

    const char* getDiscoveryTopic() const {
        int bufferSize = strlen(config.INTEGRATION_NAME) + strlen("/discovery") + 1;
        char* discoveryTopic = new char[bufferSize];
        sprintf(discoveryTopic, "%s/discovery", config.INTEGRATION_NAME);
        return discoveryTopic;
    }

    const char* getGetTopic(const char* type, const char* unique_id) const {
        int bufferSize = strlen(config.INTEGRATION_NAME) + strlen(type) + strlen(unique_id) + strlen("/get") + 2;
        char* getTopic = new char[bufferSize];
        sprintf(getTopic, "%s/%s/%s/get", config.INTEGRATION_NAME, type, unique_id);
        return getTopic;
    }

    const char* getSetTopic(const char* type, const char* unique_id) const {
        int bufferSize = strlen(config.INTEGRATION_NAME) + strlen(type) + strlen(unique_id) + strlen("/set") + 2;
        char* setTopic = new char[bufferSize];
        sprintf(setTopic, "%s/%s/%s/set", config.INTEGRATION_NAME, type, unique_id);
        return setTopic;
    }
};

#endif // ENTITYFACTORY_H
