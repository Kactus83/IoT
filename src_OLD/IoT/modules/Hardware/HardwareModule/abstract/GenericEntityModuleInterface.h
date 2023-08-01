#ifndef GENERICHARDWAREMODULE
#define GENERICHARDWAREMODULE

#include <Arduino.h>
#include "../../../Connectivity/abstract/MQTTMessagesManagerInterface.h"

class GenericHardwareModule {
public:
    virtual ~GenericHardwareModule() {}

    virtual void setMessageManager(MQTTMessagesManagerInterface& messagesManager) = 0;
    virtual void setup() = 0;
    virtual void reconnect() = 0;
    virtual void loop() = 0;
    virtual void handleMQTTMessage(const String& topic, const String& message) = 0;
    virtual bool handlesTopic(const String& topic) const = 0;  // Nouvelle fonction

};

#endif // GENERICHARDWAREMODULE
