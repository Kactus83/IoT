#ifndef HARDWAREMODULESMANAGER
#define HARDWAREMODULESMANAGER

#include <Arduino.h>
#include "../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class HardwareModulesManager {
public:
    virtual ~HardwareModulesManager() {}

    virtual void setMessagesManager(MQTTMessagesManagerInterface& messageManager) = 0;
    virtual void setupEntities() = 0;
    virtual void handleHomeAssistantConnectionInterruption() = 0;
    virtual void handleIncomingMQTTMessage(const String& message, const String& topic) = 0;
    virtual void entitiesLoop() = 0;
};

#endif // HARDWAREMODULESMANAGER
