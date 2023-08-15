#ifndef ENTITY_INFO_H
#define ENTITY_INFO_H

/**
 * @brief Holds general information for an entity.
 * 
 * This struct encapsulates necessary data for communication with 
 * remote home automation systems.
 */
struct EntityInfo
{
    const char* name;       // Name of the entity
    const char* type;       // Type of the entity
    const char* unique_id;  // Unique identifier for the entity
};

#endif // ENTITY_INFO_H
