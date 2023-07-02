#ifndef ENTITYSTATE_H
#define ENTITYSTATE_H

#include <ArduinoJson.h>

class EntityState {
protected:

  // For entity or home assistant process
  bool enabled;

  // For internal process
  bool hasBeenSent;

public:
  EntityState(bool enabled = true, bool hasBeenSent = false);
  void populateJson(JsonObject& json);
  void updateFromJson(const JsonObject& json);
  bool isEnabled();
  void setEnabled(bool enabled);
  bool isHasBeenSent();
  void setHasBeenSent(bool hasBeenSent);
};

#endif // ENTITYSTATE_H