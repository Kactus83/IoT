#include "Entity.h"

Entity::Entity(DeviceConfig& deviceConfig, String unique_id, String type, ConnectivityManager& connectivityManager)
  : entityConfig(unique_id, type), entityMessageManager(deviceConfig, entityConfig, entityState, connectivityManager) {}

void Entity::setup() {
  entityMessageManager.setup();
}

void Entity::loop() {
  entityMessageManager.loop();
}
