#include "Entity.h"

Entity::Entity(String unique_id, String type, ConnectivityManager& connectivityManager)
  : entityConfig(unique_id, type), 
    entityMessageManager(Config::getInstance().getDeviceConfig(), entityConfig, entityState, connectivityManager) {}

void Entity::setup() {
  entityMessageManager.setup();
  setupEntity();  // Call the entity-specific setup function
}

void Entity::loop() {
  entityMessageManager.checkAndSendState();
  process();  // Process entity-specific tasks
  entityMessageManager.loop();
}
