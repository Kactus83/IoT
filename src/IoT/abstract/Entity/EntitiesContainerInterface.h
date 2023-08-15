#ifndef ENTITIES_CONTAINER_INTERFACE_H
#define ENTITIES_CONTAINER_INTERFACE_H

#include "EntityInterface.h"

/**
 * @brief Interface for a container that holds multiple entities.
 * 
 * This interface provides methods for querying entities and their count.
 */
class EntitiesContainerInterface
{
public:
    virtual ~EntitiesContainerInterface() {}
    
    /**
     * @brief Returns the number of entities in the container.
     * 
     * @return The count of entities.
     */
    virtual int count() const = 0;
    
    /**
     * @brief Fetches the entity at a given index.
     * 
     * @param index The index of the desired entity.
     * @return A pointer to the entity interface.
     */
    virtual EntityInterface* getEntity(int index) = 0;
};

#endif // ENTITIES_CONTAINER_INTERFACE_H
