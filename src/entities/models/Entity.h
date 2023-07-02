#ifndef ENTITY_H
#define ENTITY_H

#include <ArduinoJson.h>
#include "EntityConfig.h"
#include "EntityState.h"
#include "EntityMessageManager.h"

class Entity {
protected:
  EntityConfig entityConfig;
  EntityState entityState;
  EntityMessageManager entityMessageManager;

public:
  Entity(DeviceConfig& deviceConfig, String unique_id, String type, ConnectivityManager& connectivityManager);

  virtual void setup();
  virtual void loop();
  virtual void process() = 0; // Pure virtual function makes this class Abstract class
};

#endif // ENTITY_H
