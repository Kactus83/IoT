#include <vector>
#include <sstream>
#include "../connectivity/ConnectivityManager.h"
#include "./models/Entity.h"
#include "./models/EntityConfig.h"
#include "./models/EntityState.h"
#include "./RGB_LED/RGBLEDEntity.h"
#include "../config/Config.h"

class EntityManager {
private:
  std::vector<Entity*> entities; 
  ConnectivityManager& connectivityManager;
  int rgbLedEntityCount = 0;

public:
  EntityManager(ConnectivityManager& connectivityManager) : connectivityManager(connectivityManager) {}
  
  void addEntity(Entity& entity) {
    entities.push_back(&entity);
  }

  void addRGBLEDEntity(int ledPin, int numOfLED) {
      std::ostringstream uniqueIdStream;
      uniqueIdStream << "RGBLED_" << rgbLedEntityCount << "_" << Config::getInstance().getDeviceConfig().getUniqueId();
      String unique_id = uniqueIdStream.str().c_str();
      RGBLEDEntity* newEntity = new RGBLEDEntity(unique_id, ledPin, numOfLED, connectivityManager);
      addEntity(*newEntity);
      rgbLedEntityCount++;
  }

  void setup() {
    for (auto& entity : entities) {
      entity->setup();
    }
  }

  void loop() {
    for (auto& entity : entities) {
      entity->loop();
    }
  }
};
