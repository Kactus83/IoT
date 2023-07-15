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
        entityCount++;
        return true;
    }

    String generateUniqueID(const String& type) {
        return config.DEVICE_NAME + "_" + type + "_" + String(entityCount);
    }

    String getDiscoveryTopic() const {
        return config.INTEGRATION_NAME + "/config";
    }

    String getGetTopic(const String& type, const String& unique_id) const {
        return config.INTEGRATION_NAME + "/" + type + "/" + unique_id + "/get";
    }

    String getSetTopic(const String& type, const String& unique_id) const {
        return config.INTEGRATION_NAME + "/" + type + "/" + unique_id + "/set";
    }
};

#endif // ENTITYFACTORY_H
