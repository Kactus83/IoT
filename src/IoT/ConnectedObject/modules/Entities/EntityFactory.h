#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <Arduino.h>
#include <map>
#include "./models/abstract/GenericEntityInterface.h"
#include "../Config/DTO/DeviceConfig.h"
#include "../Messages/MessagesManagerInterface.h"
#include "./models/entities/light/WS12_RGB_LED/WS12_RGB_LED_Entity.h"

class EntityFactory {
public:
    EntityFactory(const DeviceConfig& config, MessagesManagerInterface& messagesManager) 
    : config(config), messagesManager(messagesManager) {}

    GenericEntityInterface* createEntity(const EntitySettings& settings) {
        if(!checkEntitiesCount())
            return nullptr;

            if (settings.type == "led_ws12") {
                EntityInfo info;
                info.type = settings.type;
                info.unique_id = generateUniqueID(settings.type);
                info.discoveryTopic = getDiscoveryTopic();
                info.getTopic = getGetTopic(settings.type, info.unique_id);
                info.setTopic = getSetTopic(settings.type, info.unique_id);

                return new WS12_RGB_LED_Entity(info, messagesManager, static_cast<const WS12_RGB_LED_Settings&>(settings));
            }


        return nullptr;
    }

private:
    DeviceConfig config;
    MessagesManagerInterface& messagesManager;
    std::map<String, int> entityCountByType;
    int totalEntityCount = 0;

    bool checkEntitiesCount() {
        if(totalEntityCount >= config.MAX_ENTITIES) {
            return false;
        }
        return true;
    }

    String generateUniqueID(const String& type) {
        String unique_id = config.INTEGRATION_NAME + "_" + type;

        // Add the number of entities of this type, if more than one
        if(entityCountByType[type] > 0) {
            unique_id += "_" + String(entityCountByType[type] + 1);
        }

        entityCountByType[type]++;
        totalEntityCount++;

        return unique_id;
    }

    String getDiscoveryTopic() const {
        return config.INTEGRATION_NAME + "/discovery";
    }

    String getGetTopic(const String& type, const String& unique_id) const {
        return config.INTEGRATION_NAME + "/" + type + "/" + unique_id + "/get";
    }

    String getSetTopic(const String& type, const String& unique_id) const {
        return config.INTEGRATION_NAME + "/" + type + "/" + unique_id + "/set";
    }
};

#endif // ENTITYFACTORY_H
