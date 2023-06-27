#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <Arduino.h>
#include "../entities/RGB_LED/RGB_LED_State.h"

class MessageHandler {
private:
  String lastMessage;
  RGB_LED_State lastState; 

public:

  bool stateChanged = false;
  void handleMessage(char* topic, byte* payload, unsigned int length) {
    // For now, just convert the payload to a string and store it
    char msg[length + 1];
    memcpy(msg, payload, length);
    msg[length] = '\0'; // don't forget the null terminator
    lastMessage = String(msg);
  }

  bool MessageHandler::hasNewMessage() const {
  return lastMessage.length() > 0; 
  }

  bool hasStateChanged() const {
    return stateChanged;
  }

  void handleState(const RGB_LED_State& state) {
    lastState = state;
    stateChanged = true; // Indicate that the state has changed
  }

  String getLastMessage() const {
    return lastMessage;
  }

  RGB_LED_State getLastState() const {
    return lastState;
  }

  void clearLastMessage() {
    lastMessage = "";
  }

  void clearLastState() {
    lastState = RGB_LED_State();
  }
};

#endif
