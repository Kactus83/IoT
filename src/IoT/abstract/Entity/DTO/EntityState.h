#ifndef ENTITY_STATE_H
#define ENTITY_STATE_H

/**
 * @brief Represents the internal state of an entity.
 * 
 * Contains flags to indicate the state of the entities. 
 * Connectors uses this data to choose what action to
 * execute on entities.
 */
struct EntityState
{
    bool shouldSendStateUpdate = false; // Flag indicating if a state update should be sent
    bool hasLostConnexion = false;      // Flag indicating if the entity has lost its connection
};

#endif // ENTITY_STATE_H
