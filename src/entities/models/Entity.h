// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "EntityInfo.h"
#include "EntityState.h"
#include "../../connectivity/ConnectivityManager.h"

class Entity {
protected:
  EntityInfo entityInfo;
  EntityState entityState;
  ConnectivityManager& connectivityManager;
  void sendDiscoveryMessage();
  void processIncomingMessage();
  void process();
  void checkAndSendState();
  
public:
  Entity(DeviceConfig& deviceConfig, String unique_id, String type, ConnectivityManager& connectivityManager);
  void setup();
  void loop();
};

#endif // ENTITY_H