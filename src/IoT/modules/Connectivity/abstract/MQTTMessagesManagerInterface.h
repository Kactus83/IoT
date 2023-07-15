#ifndef MQTTMESSAGESMANAGERINTERFACE_H
#define MQTTMESSAGESMANAGERINTERFACE_H

#include <Arduino.h>

class MQTTMessagesManagerInterface {
public:
    virtual ~MQTTMessagesManagerInterface() {}
    virtual void subscribeToMQTTTopic(const char* topic) = 0;
    virtual void sendMQTTMessage(const char* topic, const char* message) = 0;
};

#endif
