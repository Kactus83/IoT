#ifndef ENTITYCONFIG_H
#define ENTITYCONFIG_H

#include <String.h>

class EntityConfig {
protected:
  String unique_id;
  String type;

public:
  EntityConfig(String unique_id, String type) 
    : unique_id(unique_id), type(type) {}

  String getUniqueId() { return unique_id; }
  String getType() { return type; }
};

#endif // ENTITYCONFIG_H
