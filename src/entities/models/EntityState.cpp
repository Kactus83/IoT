#include "EntityState.h"

EntityState::EntityState(bool enabled, bool hasBeenSent) : enabled(enabled), hasBeenSent(hasBeenSent) {}

void EntityState::populateJson(JsonObject& json) {
  json["enabled"] = enabled;
}

void EntityState::updateFromJson(const JsonObject& json) {
  if(json.containsKey("enabled")) {
    enabled = json["enabled"];
  }
}

bool EntityState::isEnabled() {
  return enabled;
}

void EntityState::setEnabled(bool enabled) {
  this->enabled = enabled;
}

bool EntityState::isHasBeenSent() {
  return hasBeenSent;
}

void EntityState::setHasBeenSent(bool hasBeenSent) {
  this->hasBeenSent = hasBeenSent;
}