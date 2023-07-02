#include "EntityMessageManager.h"

EntityMessageManager::EntityMessageManager(DeviceConfig& deviceConfig, EntityConfig& entityConfig, EntityState& entityState, ConnectivityManager& connectivityManager)
    : deviceConfig(deviceConfig), entityConfig(entityConfig), entityState(entityState), connectivityManager(connectivityManager) {
      postAddress = String(deviceConfig.getIntegrationName()) + "/" + entityConfig.getUniqueId() + "/set";
      discoveryTopic = String(deviceConfig.getIntegrationName()) + "/discovery";
}


void EntityMessageManager::setup() {
  connectivityManager.subscribeToTopic(postAddress.c_str());
  sendDiscoveryMessage();
}

void EntityMessageManager::loop() {
  processIncomingMessage();
  checkAndSendState();
}

void EntityMessageManager::sendDiscoveryMessage() {
  // Création du payload de découverte au moment de l'envoi
  String discoveryPayload = String("{\"unique_id\": \"") + entityConfig.getUniqueId() + "\", \"type\": \"" + entityConfig.getType() + "\", \"name\": \"" + entityConfig.getName() + "\"}";
  
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, discoveryPayload);
  JsonObject state = doc.createNestedObject("state");
  entityState.populateJson(state);

  String output;
  serializeJson(doc, output);
  connectivityManager.sendMQTTMessage(discoveryTopic.c_str(), output.c_str());
}

void EntityMessageManager::checkAndSendState() {
  if(entityState.shoudBeSent() && entityState.isEnabled()) {
    DynamicJsonDocument doc(1024);
    JsonObject state = doc.createNestedObject("state");
    entityState.populateJson(state);

    String output;
    serializeJson(doc, output);
    connectivityManager.sendMQTTMessage(postAddress.c_str(), output.c_str());
    entityState.setHasBeenUpdated(false);
  }
}

void EntityMessageManager::processIncomingMessage() {
  String message = connectivityManager.getLastMQTTMessage(postAddress.c_str());
  if(message.length() > 0) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, message);
    JsonObject state = doc["state"];
    entityState.updateFromJson(state);
    connectivityManager.clearLastMQTTMessage(postAddress.c_str());
  }
}
