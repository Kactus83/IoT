// EntitiesContainerInterface.h

#ifndef ENTITIES_CONTAINER_INTERFACE_H
#define ENTITIES_CONTAINER_INTERFACE_H

#include "EntityInterface.h"

class EntitiesContainerInterface
{
public:
    virtual ~EntitiesContainerInterface() {}
    
    // Renvoie le nombre d'entités dans le conteneur
    virtual int count() const = 0;
    
    // Renvoie un pointeur vers l'entité à l'index spécifié
    virtual EntityInterface* getEntity(int index) = 0;
};

#endif // ENTITIES_CONTAINER_INTERFACE_H
