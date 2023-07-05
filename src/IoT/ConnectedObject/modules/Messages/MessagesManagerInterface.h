
#ifndef MESSAGESMANAGERINTERFACE_H
#define MESSAGESMANAGERINTERFACE_H

#include <Arduino.h>

class MessagesManagerInterface {
public:
    virtual ~MessagesManagerInterface() {}
    virtual void handleIncomingMessage(const String& topic, const String& message) = 0;
    virtual void sendMessage(const String& topic, const String& message) = 0;
    virtual void subscribeToTopic(const String& topic) = 0;
};

#endif
