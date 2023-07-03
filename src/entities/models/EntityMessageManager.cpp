#include "EntityMessageManager.h"

EntityMessageManager::EntityMessageManager(DeviceConfig& deviceConfig, EntityConfig* entityConfig, EntityState* entityState, ConnectivityManager& connectivityManager)
    : deviceConfig(deviceConfig), entityConfig(entityConfig), entityState(entityState), connectivityManager(connectivityManager) {
      postAddress = String(deviceConfig.getIntegrationName()) + "/" + entityConfig->getUniqueId() + "/get";
      listeningAddress = String(deviceConfig.getIntegrationName()) + "/" + entityConfig->getUniqueId() + "/set";
      discoveryTopic = String(deviceConfig.getIntegrationName()) + "/discovery";
}

void EntityMessageManager::setup() {
  connectivityManager.subscribeToTopic(listeningAddress.c_str());
  sendDiscoveryMessage();
}

void EntityMessageManager::loop() {
  processIncomingMessage();
  checkAndSendState();
}

void EntityMessageManager::sendDiscoveryMessage() {
  // Création du payload de découverte au moment de l'envoi
  String discoveryPayload = String("{\"unique_id\": \"") + entityConfig->getUniqueId() + "\", \"type\": \"" + entityConfig->getType() + "\", \"name\": \"" + entityConfig->getName() + "\"}";
  
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, discoveryPayload);
  JsonObject root = doc.as<JsonObject>();
  entityState->populateJson(root);

  String output;
  serializeJson(doc, output);
  connectivityManager.sendMQTTMessage(discoveryTopic.c_str(), output.c_str());
}

void EntityMessageManager::checkAndSendState() {
  if(entityState->shoudBeSent() && entityState->isEnabled()) {
    DynamicJsonDocument doc(1024);
    JsonObject root = doc.as<JsonObject>();
    entityState->populateJson(root);

    String output;
    serializeJson(doc, output);
    
    if (output != NULL && output.length() > 0) { // Vérification si la chaîne de caractères est non vide
      connectivityManager.sendMQTTMessage(postAddress.c_str(), output.c_str());
      entityState->resetHasBeenUpdated();
    } else {
      Serial.println("Failed to send MQTT message. JSON serialized string is empty.");
    }
  }
}

void EntityMessageManager::processIncomingMessage() {
  if (connectivityManager.isNewMessageAvailable(listeningAddress.c_str())) {
    String message = connectivityManager.getLastMQTTMessage(listeningAddress.c_str());
    if (message.length() > 0 && message != "null") {
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, message);

      // Log the received message
      Serial.print("Received message: ");
      serializeJson(doc, Serial);
      Serial.println();

      // Process the incoming message
      entityState->updateFromJson(doc.as<JsonObject>());

      // Clear the last message and update new message availability
      connectivityManager.clearLastMQTTMessage(listeningAddress.c_str());
    }
  }
}


