#ifndef ABSTRACT_ENTITIES_CONTAINER_H
#define ABSTRACT_ENTITIES_CONTAINER_H

#include "EntitiesContainerInterface.h"
#include "EntityInterface.h"
#include <cstring>

/**
 * @brief Represents an abstract container for entities.
 * 
 * This class provides base functionality for a container that holds 
 * multiple entities. It also offers utility to generate unique 
 * identifiers for entities.
 */
class AbstractEntitiesContainer : public EntitiesContainerInterface
{
public:
    /**
     * @brief Constructs an abstract entity container.
     * 
     * @param entities Pointer to an array of entity interfaces.
     * @param size The number of entities in the container.
     */
    AbstractEntitiesContainer(EntityInterface** entities, int size)
        : entities_(entities), size_(size)
    {
    }
    
    /**
     * @brief Returns the number of entities in the container.
     * 
     * @return The count of entities.
     */
    int count() const override
    {
        return size_;
    }
    
    /**
     * @brief Fetches the entity at a given index.
     * 
     * @param index The index of the desired entity.
     * @return A pointer to the entity interface, or nullptr if index is out-of-range.
     */
    EntityInterface* getEntity(int index) override
    {
        if (index >= 0 && index < size_)
            return entities_[index];
        // TODO: Implement error handling for out-of-range index
        return nullptr;
    }

protected:
    EntityInterface** entities_;   ///< Array of pointers to entity interfaces.
    int size_;                     ///< Count of entities in the container.
    
    /**
     * @brief Generates a unique identifier for an entity.
     * 
     * @param base The base string of the identifier.
     * @param suffix An optional suffix to append to the base.
     * @return A string representing the unique identifier.
     */
    const char* generateUniqueId(const char* base, const char* suffix = nullptr)
    {
        if(suffix == nullptr)
            return base;
        
        // Determine the size of the resulting string.
        int baseLength = strlen(base);
        int suffixLength = strlen(suffix);

        // Allocate memory for the resulting string.
        char* uniqueId = new char[baseLength + suffixLength + 2];  // +2 for the underscore and the null-terminator.

        // Copy base into uniqueId.
        strcpy(uniqueId, base);

        // Append underscore.
        uniqueId[baseLength] = '_';

        // Append suffix to uniqueId.
        strcpy(uniqueId + baseLength + 1, suffix);

        return uniqueId;
    }
};

#endif // ABSTRACT_ENTITIES_CONTAINER_H
