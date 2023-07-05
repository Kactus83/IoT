#ifndef ENTITYCONFIG_H
#define ENTITYCONFIG_H

#include <String.h>

class EntityConfig {
protected:
  String unique_id;
  String type;
  String name;  

public:
  EntityConfig(String unique_id, String type, String name) 
    : unique_id(unique_id), type(type), name(name) {}

  String getUniqueId() { return unique_id; }
  String getType() { return type; }
  String getName() { return name; }  
};

#endif // ENTITYCONFIG_H
