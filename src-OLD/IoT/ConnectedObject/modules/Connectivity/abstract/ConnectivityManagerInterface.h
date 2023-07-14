#ifndef CONNECTIVITYMANAGERINTERFACE_H
#define CONNECTIVITYMANAGERINTERFACE_H

#include <Arduino.h>

class ConnectivityManagerInterface {
public:
    virtual ~ConnectivityManagerInterface() {}
    virtual void connectHomeAssistant() = 0;
    virtual void updateHomeAssistantConnection() = 0;
    virtual void subscribeToMQTTTopic(const String& topic) = 0;
    virtual void sendMQTTMessage(const String& topic, const String& message) = 0;
};

#endif
