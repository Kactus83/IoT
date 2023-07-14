#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <Arduino.h>
#include "../Config/DTO/DeviceConfig.h"
#include "./abstract/GenericEntityInterface.h"
#include "./abstract/DTO/EntitySettings.h"
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"
#include "./implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Settings.h"
#include "./implementations/lights/WS12_RGB_LED/WS12_RGB_LED_Entity.h"

// Ajoutez ceci avant la définition de la classe EntityFactory
union EntitySettingsUnion {
    EntitySettings base;
    WS12_RGB_LED_Settings led_rgb;
};

class EntityFactory {
public:
    EntityFactory(const DeviceConfig& config) : config(config) {}

    void setMessagesManager(MQTTMessagesManagerInterface& manager) {
        messagesManager = &manager;
    }

    GenericEntityInterface* createEntity(const EntitySettingsUnion& settingsUnion) {
        if (!checkEntitiesCount())
            return nullptr;

        if (settingsUnion.base.type == "led_rgb") {
            EntityInfo info;
            info.type = settingsUnion.base.type;
            info.unique_id = generateUniqueID(settingsUnion.base.type);
            info.discoveryTopic = getDiscoveryTopic();
            info.getTopic = getGetTopic(settingsUnion.base.type, info.unique_id);
            info.setTopic = getSetTopic(settingsUnion.base.type, info.unique_id);

            return new WS12_RGB_LED_Entity(info, *messagesManager, settingsUnion.led_rgb);
        }

        return nullptr;
    }

private:
    DeviceConfig config;
    MQTTMessagesManagerInterface* messagesManager = nullptr;
    int entityCount = 0;
    int maxEntities;

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
