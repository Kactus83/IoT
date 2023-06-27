// MessageHandler.h
#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <Arduino.h>

class MessageHandler {
private:
  String lastMessage;

public:
  void handleMessage(char* topic, byte* payload, unsigned int length) {
    // For now, just convert the payload to a string and store it
    char msg[length + 1];
    memcpy(msg, payload, length);
    msg[length] = '\0'; // don't forget the null terminator
    lastMessage = String(msg);
  }

  String getLastMessage() const {
    return lastMessage;
  }

  void clearLastMessage() {
    lastMessage = "";
  }
};

#endif
