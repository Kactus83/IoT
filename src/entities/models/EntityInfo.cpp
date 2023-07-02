#include "EntityInfo.h"

EntityInfo::EntityInfo(DeviceConfig& deviceConfig, String unique_id, String type)
  : deviceConfig(deviceConfig), unique_id(unique_id), type(type) {}
  
String EntityInfo::getPostAddress() {
  return String(deviceConfig.getIntegrationName()) + "/" + unique_id + "/set";
}

String EntityInfo::getDiscoveryTopic() {
  return String(deviceConfig.getIntegrationName()) + "/discovery";
}

String EntityInfo::getDiscoveryPayload() {
  DynamicJsonDocument doc(1024);
  
  doc["unique_id"] = unique_id;
  doc["type"] = type;
  
  String output;
  serializeJson(doc, output);

  return output;
}
