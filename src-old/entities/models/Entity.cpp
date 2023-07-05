#include "Entity.h"

Entity::Entity(EntityConfig* config, EntityState* state, ConnectivityManager& connectivityManager) {
  entityConfig = config;
  entityState = state;
  entityMessageManager = new EntityMessageManager(Config::getInstance().getDeviceConfig(), config, state, connectivityManager);
}

Entity::~Entity() {
  delete entityMessageManager;
  // Vous devrez peut-être aussi libérer entityConfig et entityState si ces objets ne sont pas gérés ailleurs
}

void Entity::setup() {
  entityMessageManager->setup();
  setupEntity();  // Call the entity-specific setup function
}

void Entity::loop() {
  entityMessageManager->loop();
  process();  // Process entity-specific tasks
  entityMessageManager->checkAndSendState();
}
