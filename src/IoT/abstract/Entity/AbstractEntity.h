#ifndef ABSTRACT_ENTITY_H
#define ABSTRACT_ENTITY_H

#include "EntityInterface.h"

template <typename HardwareState>
class AbstractEntity : public EntityInterface
{
public:
    const EntityInfo& getInfo() const override { return info_; }
    EntityState& getState() override { return state_; }
    const EntityState& getState() const override { return state_; }
    HardwareState& getHardwareState() { return hardwareState_; }
    const HardwareState& getHardwareState() const { return hardwareState_; }

protected:
    AbstractEntity(const char* name, const char* type, const char* unique_id)
    : EntityInterface{EntityInfo{name, type, unique_id}, EntityState{}}, hardwareState_() {}

private:
    HardwareState hardwareState_;
};

#endif // ABSTRACT_ENTITY_H