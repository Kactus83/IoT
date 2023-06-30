#ifndef ENTITYINFO_H
#define ENTITYINFO_H

#include <ArduinoJson.h>
#include "../../config/Device/DeviceConfig.h"

class EntityInfo {
protected:
  DeviceConfig& deviceConfig;
  String unique_id;

public:
  EntityInfo(DeviceConfig& deviceConfig, String unique_id);
  String getPostAddress();
  String getDiscoveryTopic();
  String getDiscoveryPayload();
};

#endif // ENTITYINFO_H