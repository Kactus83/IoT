#ifndef ENTITYMESSAGEMANAGER_H
#define ENTITYMESSAGEMANAGER_H

#include <ArduinoJson.h>
#include "../../config/Device/DeviceConfig.h"
#include "EntityConfig.h"
#include "EntityState.h"
#include "../../connectivity/ConnectivityManager.h"

class EntityMessageManager {
private:
  DeviceConfig& deviceConfig;
  EntityConfig* entityConfig; 
  EntityState* entityState; 
  ConnectivityManager& connectivityManager;
  String postAddress;
  String listeningAddress;
  String discoveryTopic;

public:
  EntityMessageManager(DeviceConfig& deviceConfig, EntityConfig* entityConfig, EntityState* entityState, ConnectivityManager& connectivityManager);
  void setup();
  void loop();
  void checkAndSendState();
  
private:
  void sendDiscoveryMessage();
  void processIncomingMessage();
};

#endif // ENTITYMESSAGEMANAGER_H
