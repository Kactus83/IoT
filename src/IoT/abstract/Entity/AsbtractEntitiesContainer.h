#ifndef ABSTRACT_ENTITIES_CONTAINER_H
#define ABSTRACT_ENTITIES_CONTAINER_H

#include "EntitiesContainerInterface.h"
#include "EntityInterface.h"
#include <cstring>

class AbstractEntitiesContainer : public EntitiesContainerInterface
{
public:
    AbstractEntitiesContainer(EntityInterface** entities, int size)
        : entities_(entities), size_(size)
    {
    }
    
    int count() const override
    {
        return size_;
    }
    
    EntityInterface* getEntity(int index) override
    {
        if (index >= 0 && index < size_)
            return entities_[index];
        // should include error handling for out-of-range index
        return nullptr;
    }

protected:
    EntityInterface** entities_;
    int size_;
    
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
