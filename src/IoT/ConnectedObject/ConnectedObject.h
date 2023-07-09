// ConnectedObject.h
#ifndef CONNECTEDOBJECT_H
#define CONNECTEDOBJECT_H

#include "./modules/Config/ConfigManager.h"
#include "./modules/Connectivity/abstract/ConnectivityManagerInterface.h"
#include "./modules/Entities/EntitiesManagerInterface.h"
#include "./modules/Messages/MessagesManagerInterface.h"
#include "./modules/Config/DTO/FactorySettings.h"

template<class T_ConfigManager, class T_ConnectivityManager, class T_EntitiesManager, class T_MessagesManager>
class ConnectedObject {
public:
    ConnectedObject(FactorySettings& settings)
    : factorySettings(settings) {
        // Initialize managers with the right configurations
        configManager = new T_ConfigManager(settings);
        connectivityManager = new T_ConnectivityManager(configManager->getConnectivityConfig());
        entitiesManager = new T_EntitiesManager(configManager->getDeviceConfig());
        messagesManager = new T_MessagesManager();

        // Initialize messagesManager after other managers have been created
        messagesManager->initialize(*connectivityManager, *entitiesManager);
    }

    virtual ~ConnectedObject() {
        delete configManager;
        delete connectivityManager;
        delete entitiesManager;
        delete messagesManager;
    };

    void setup() {
        connectivityManager->connectHomeAssistant();
        entitiesManager->setupEntities();
    }

    void loop() {
        connectivityManager->updateHomeAssistantConnection();
        entitiesManager->entitiesLoop();
    }

private:
    FactorySettings& factorySettings;
    ConfigManager* configManager;
    ConnectivityManagerInterface* connectivityManager;
    EntitiesManagerInterface* entitiesManager;
    MessagesManagerInterface* messagesManager;
};

#endif
