#ifndef ENTITYSTATE_H
#define ENTITYSTATE_H

#include <ArduinoJson.h>

class EntityState {
protected:
  bool enabled;
  bool hasBeenSent;

public:
  EntityState(bool enabled = false, bool hasBeenSent = false);
  void populateJson(JsonObject& json);
  void updateFromJson(const JsonObject& json);
  bool isEnabled();
  void setEnabled(bool enabled);
  bool isHasBeenSent();
  void setHasBeenSent(bool hasBeenSent);
};

#endif // ENTITYSTATE_H