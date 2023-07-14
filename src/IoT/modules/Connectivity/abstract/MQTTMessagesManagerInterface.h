#ifndef MQTTMESSAGESMANAGERINTERFACE_H
#define MQTTMESSAGESMANAGERINTERFACE_H

#include <Arduino.h>

class MQTTMessagesManagerInterface {
public:
    virtual ~MQTTMessagesManagerInterface() {}
    virtual void subscribeToMQTTTopic(const String& topic) = 0;
    virtual void sendMQTTMessage(const String& topic, const String& message) = 0;
};

#endif
