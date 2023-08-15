#ifndef ENTITY_INTERFACE_H
#define ENTITY_INTERFACE_H

#include "./DTO/EntityInfo.h"
#include "./DTO/EntityState.h"
#include "./DTO/AbstractEntityHardwareState.h"

/**
 * @brief An interface for system entities.
 * 
 * This interface defines the necessary methods for connectors to interact 
 * with any entity within the system uniformly. 
 */
class EntityInterface
{
public:
    // Virtual destructor to ensure proper deletion in case of inheritance.
    virtual ~EntityInterface() {} 

    // Retrieve the basic information of the entity.
    virtual const EntityInfo& getInfo() const = 0;

    // Retrieve the current state of the entity.
    virtual EntityState& getState() = 0;
    virtual const EntityState& getState() const = 0;

    // Retrieve the hardware state of the entity.
    virtual AbstractEntityHardwareState& getHardwareState() = 0;

protected:
    // Protected constructor taking the entity's information and state.
    EntityInterface(EntityInfo info, EntityState state) : info_(info), state_(state) {}

    EntityInfo info_;         // Information about the entity
    EntityState state_;      // Current state of the entity
};

#endif // ENTITY_INTERFACE_H
