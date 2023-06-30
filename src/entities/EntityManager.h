#include <vector>
#include "../connectivity/ConnectivityManager.h"
#include "./models/Entity.h"
#include "./models/EntityInfo.h"
#include "./models/EntityState.h"

class EntityManager {
private:
  std::vector<Entity*> entities; 
  ConnectivityManager& connectivityManager;

public:
  EntityManager(ConnectivityManager& connectivityManager) : connectivityManager(connectivityManager) {}
  
  void addEntity(Entity& entity) {
    entities.push_back(&entity);
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