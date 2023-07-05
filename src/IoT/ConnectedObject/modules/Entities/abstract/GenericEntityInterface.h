#ifndef GENERICENTITYINTERFACE_H
#define GENERICENTITYINTERFACE_H

#include <Arduino.h>

class GenericEntityInterface {
public:
    virtual ~GenericEntityInterface() {}

    virtual void setup() = 0;
    virtual void reconnect() = 0;
    virtual void loop() = 0;
    virtual void handleMQTTMessage(const String& topic, const String& message) = 0;
};

#endif // GENERICENTITYINTERFACE_H
