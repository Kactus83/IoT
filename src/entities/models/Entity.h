#ifndef ENTITY_H
#define ENTITY_H

#include <ArduinoJson.h>
#include "EntityConfig.h"
#include "EntityState.h"
#include "EntityMessageManager.h"
#include "../../config/Config.h" 

class Entity {
protected:
  EntityMessageManager* entityMessageManager = nullptr;

public:
  Entity(EntityConfig& config, EntityState& state, ConnectivityManager& connectivityManager);
  virtual ~Entity();

  virtual void setup();
  virtual void loop();
  virtual void process() = 0; // Pure virtual function makes this class Abstract class
  virtual void setupEntity() = 0; // Additional virtual function for entity-specific setup
};

#endif // ENTITY_H
