#ifndef ENTITYSTATE_H
#define ENTITYSTATE_H

#include <ArduinoJson.h>

class EntityState {
protected:
  bool enabled;
  bool hasBeenUpdated;

public:
  EntityState(bool enabled = true, bool hasBeenUpdated = false) 
    : enabled(enabled), hasBeenUpdated(hasBeenUpdated) {}

  void populateJson(JsonObject& json) { json["enabled"] = enabled; }
  void updateFromJson(const JsonObject& json) {
    if(json.containsKey("enabled")) {
      enabled = json["enabled"];
    }
    setHasBeenUpdated(true);
  }
  bool isEnabled() { return enabled; }
  void setEnabled(bool enabled) { this->enabled = enabled; }
  bool shoudBeSent() { return hasBeenUpdated; }
  void setHasBeenUpdated(bool hasBeenUpdated) { this->hasBeenUpdated = hasBeenUpdated; }
};

#endif // ENTITYSTATE_H
