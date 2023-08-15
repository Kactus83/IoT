#ifndef ABSTRACT_ENTITY_H
#define ABSTRACT_ENTITY_H

#include "EntityInterface.h"

/**
 * @brief An abstract representation of entities.
 * 
 * Specifies how an entity should be constructed. This abstract class
 * also ensures that the specific hardware state has a particular type,
 * although no compile-time check is enforced due to hardware constraints.
 * SpecificHardwareState is useful for hardware managers.
 */
template <typename HardwareState>
class AbstractEntity : public EntityInterface
{
public:
    // Override the interface methods
    const EntityInfo& getInfo() const override { return info_; }
    EntityState& getState() override { return state_; }
    const EntityState& getState() const override { return state_; }
    AbstractEntityHardwareState& getHardwareState() override { return hardwareState_; }
    
    // Retrieve the specific hardware state of the entity.
    HardwareState& getSpecificHardwareState() { return hardwareState_; }

protected:
    // Constructor initializes EntityState as empty because its data is supplied in two steps.
    AbstractEntity(const char* name, const char* type, const char* unique_id)
    : EntityInterface{EntityInfo{name, type, unique_id}, EntityState{}}, hardwareState_() {}

private:
    HardwareState hardwareState_;
};

#endif // ABSTRACT_ENTITY_H
