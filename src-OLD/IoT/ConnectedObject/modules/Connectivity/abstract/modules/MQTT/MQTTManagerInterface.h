#ifndef MQTTMANAGERINTERFACE_H
#define MQTTMANAGERINTERFACE_H

#include <Arduino.h>

class MQTTManagerInterface {
public:
    virtual ~MQTTManagerInterface() {}
    virtual void connect(void* client) = 0;
    virtual bool isConnected() = 0;
    virtual void update() = 0;
    virtual void subscribeToTopic(const String& topic) = 0;
    virtual void sendMessage(const String& topic, const String& message) = 0;
};

#endif
