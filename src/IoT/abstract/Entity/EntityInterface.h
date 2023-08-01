#ifndef ENTITY_INTERFACE_H
#define ENTITY_INTERFACE_H

#include "./DTO/EntityInfo.h"
#include "./DTO/EntityState.h"

class EntityInterface
{
public:
    virtual ~EntityInterface() {} 

    virtual const EntityInfo& getInfo() const = 0;
    virtual EntityState& getState() = 0;
    virtual const EntityState& getState() const = 0;
protected:
    EntityInterface(EntityInfo info, EntityState state) : info_(info), state_(state) {}

    EntityInfo info_;
    EntityState state_;
};

#endif // ENTITY_INTERFACE_H