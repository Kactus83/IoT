#ifndef MESSAGESMANAGER_H
#define MESSAGESMANAGER_H

#include <Arduino.h>
#include "MessagesManagerInterface.h"
#include "../Connectivity/abstract/ConnectivityManagerInterface.h"

class MessagesManager : public MessagesManagerInterface {
public:
    MessagesManager(ConnectivityManagerInterface* connectivityManager)
    : connectivityManager(connectivityManager) {}

    void handleIncomingMQTTMessage(const String& topic, const String& message) override;
    void sendMQTTMessage(const String& topic, const String& message) override {
        connectivityManager->sendMQTTMessage(topic, message);
    }
    void subscribeToMQTTTopic(const String& topic) override {
        connectivityManager->subscribeToMQTTTopic(topic);
    }

private:
    ConnectivityManagerInterface* connectivityManager;
};

#endif
