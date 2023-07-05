#ifndef GENERICENTITYINTERFACE_H
#define GENERICENTITYINTERFACE_H

#include <Arduino.h>
#include "./modules/EntityDataManagerInterface.h"
#include "./modules/EntityHardwareManagerInterface.h"
#include "./DTO/EntityInfo.h"
#include "./DTO/GenericEntityState.h"
#include "./DTO/GenericEntityState.h"

class GenericEntityInterface {
public:
    virtual ~GenericEntityInterface() {}

    virtual void setup() = 0;
    virtual void reconnect() = 0;
    virtual void loop() = 0;
    virtual void handleMQTTMessage(const String& topic, const String& message) = 0;
    
    EntityInfo info;

};

#endif // GENERICENTITYINTERFACE_H
