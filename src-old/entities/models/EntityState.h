#ifndef ENTITYSTATE_H
#define ENTITYSTATE_H

#include <ArduinoJson.h>

class EntityState {
protected:
  bool enabled;
  bool hasBeenUpdated;
  void setHasBeenUpdated(bool hasBeenUpdated) { this->hasBeenUpdated = hasBeenUpdated; }

public:
  EntityState(bool enabled = true, bool hasBeenUpdated = false) 
    : enabled(enabled), hasBeenUpdated(hasBeenUpdated) {}

  virtual void populateJson(JsonObject& json) { json["enabled"] = enabled; }
  virtual void updateFromJson(const JsonObject& json) {
    if(json.containsKey("enabled")) {
      enabled = json["enabled"];
    }
  }
  bool isEnabled() { return enabled; }
  void setEnabled(bool enabled) { this->enabled = enabled; }
  bool shoudBeSent() { return hasBeenUpdated; }
  void resetHasBeenUpdated() { this->hasBeenUpdated = false; }
};

#endif // ENTITYSTATE_H
