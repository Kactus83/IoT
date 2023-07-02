#include "Entity.h"

Entity::Entity(EntityConfig& config, EntityState& state, ConnectivityManager& connectivityManager) {
  entityMessageManager = new EntityMessageManager(Config::getInstance().getDeviceConfig(), config, state, connectivityManager);
}

Entity::~Entity() {
  delete entityMessageManager;
}

void Entity::setup() {
  entityMessageManager->setup();
  setupEntity();  // Call the entity-specific setup function
}

void Entity::loop() {
  entityMessageManager->checkAndSendState();
  process();  // Process entity-specific tasks
  entityMessageManager->loop();
}
