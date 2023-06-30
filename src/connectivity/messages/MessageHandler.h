#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <Arduino.h>
#include <map>

class MessageHandler {
private:
  std::map<String, String> topicMessages;

public:
  void handleMessage(const String& topic, byte* payload, unsigned int length) {
    // Convert the payload to a string
    char msg[length + 1];
    memcpy(msg, payload, length);
    msg[length] = '\0'; // don't forget the null terminator

    // Store the message associated with the topic
    topicMessages[topic] = String(msg);
  }

  String getLastMessage(const String& topic) const {
    // Find the last message for the topic
    auto it = topicMessages.find(topic);
    return it != topicMessages.end() ? it->second : String("");
  }

  void clearLastMessage(const String& topic) {
    topicMessages.erase(topic);
  }
};

#endif