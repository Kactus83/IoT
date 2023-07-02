#ifndef RGBLEDENTITYMESSAGEMANAGER_H
#define RGBLEDENTITYMESSAGEMANAGER_H

#include "../models/EntityMessageManager.h"
#include "RGBLEDEntityConfig.h"
#include "RGBLEDEntityState.h"

class RGBLEDEntityMessageManager : public EntityMessageManager {
public:
  RGBLEDEntityMessageManager(DeviceConfig& deviceConfig, RGBLEDEntityConfig& entityConfig, RGBLEDEntityState& entityState, ConnectivityManager& connectivityManager)
    : EntityMessageManager(deviceConfig, entityConfig, entityState, connectivityManager) {}
};

#endif // RGBLEDENTITYMESSAGEMANAGER_H
