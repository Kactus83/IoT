#include "Entity.h"

Entity::Entity(DeviceConfig& deviceConfig, String unique_id, ConnectivityManager& connectivityManager)
  : entityInfo(deviceConfig, unique_id), connectivityManager(connectivityManager) {}

void Entity::setup() {
  connectivityManager.subscribeToTopic(entityInfo.getPostAddress().c_str());
  sendDiscoveryMessage();
}

void Entity::loop() {
  checkAndSendState();
  processIncomingMessage();
}

void Entity::sendDiscoveryMessage() {
  DynamicJsonDocument doc(1024);
  String discoveryPayload = entityInfo.getDiscoveryPayload();
  deserializeJson(doc, discoveryPayload);
  JsonObject state = doc.createNestedObject("state");
  entityState.populateJson(state);
  
  String output;
  serializeJson(doc, output);
  connectivityManager.sendMQTTMessage(entityInfo.getDiscoveryTopic().c_str(), output.c_str());
}

void Entity::checkAndSendState() {
  if (!entityState.isHasBeenSent()) {
    DynamicJsonDocument doc(1024);
    JsonObject state = doc.createNestedObject("state");
    entityState.populateJson(state);
    
    String output;
    serializeJson(doc, output);
    connectivityManager.sendMQTTMessage(entityInfo.getPostAddress().c_str(), output.c_str());
    
    entityState.setHasBeenSent(true);
  }
}

void Entity::processIncomingMessage() {
  String topic = entityInfo.getPostAddress();
  String message = connectivityManager.getLastMQTTMessage(topic.c_str());
  if (message.length() > 0) {
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, message);
    if (!error) {
      entityState.updateFromJson(doc.as<JsonObject>());
    }
    connectivityManager.clearLastMQTTMessage(topic.c_str());
  }
}