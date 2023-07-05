#ifndef MESSAGESMANAGER_H
#define MESSAGESMANAGER_H

#include <Arduino.h>
#include "MessagesManagerInterface.h"
#include "../Connectivity/ConnectivityManagerInterface.h"

class MessagesManager : public MessagesManagerInterface {
public:
    MessagesManager(ConnectivityManagerInterface* connectivityManager)
    : connectivityManager(connectivityManager) {}

    void handleIncomingMessage(const String& topic, const String& message) override;
    void sendMessage(const String& topic, const String& message) override {
        connectivityManager->sendMessage(topic, message);
    }
    void subscribeToTopic(const String& topic) override {
        connectivityManager->subscribeToTopic(topic);
    }

private:
    ConnectivityManagerInterface* connectivityManager;
};

#endif
