#ifndef ENTITY_STATE_H
#define ENTITY_STATE_H

struct EntityState
{
    bool shouldSendStateUpdate = false;
    bool hasLostConnexion = false;
};

#endif // ENTITY_STATE_H