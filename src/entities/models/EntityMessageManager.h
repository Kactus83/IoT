#ifndef ENTITYMESSAGEMANAGER_H
#define ENTITYMESSAGEMANAGER_H

#include <ArduinoJson.h>
#include "../../config/Device/DeviceConfig.h"
#include "EntityConfig.h"
#include "EntityState.h"
#include "../../connectivity/ConnectivityManager.h"

class EntityMessageManager {
private:
  ConnectivityManager& connectivityManager;
  DeviceConfig& deviceConfig;
  EntityConfig& entityConfig;
  EntityState& entityState;
  String postAddress;
  String discoveryTopic;

  void sendDiscoveryMessage();
  void processIncomingMessage();

public:
  EntityMessageManager(DeviceConfig& deviceConfig, EntityConfig& entityConfig, EntityState& entityState, ConnectivityManager& connectivityManager);

  void setup();
  void loop();
  void checkAndSendState();
};

#endif // ENTITYMESSAGEMANAGER_H
