#include "./config/Config.h"
#include "./connectivity/ConnectivityManager.h"
#include "./entities/EntityManager.h"

Config& config = Config::getInstance();
ConnectivityManager connectivityManager;
EntityManager entityManager(connectivityManager);

void setup() {
  Serial.begin(9600);
  connectivityManager.begin();
  entityManager.setup();
}

void loop() {
  connectivityManager.update();
  entityManager.loop();
}
