#include "./config/Config.h"
#include "./connectivity/ConnectivityManager.h"

Config& config = Config::getInstance();
ConnectivityManager connectivityManager;

void setup() {
  Serial.begin(9600);
  connectivityManager.begin();
}

void loop() {
  connectivityManager.update();
}
