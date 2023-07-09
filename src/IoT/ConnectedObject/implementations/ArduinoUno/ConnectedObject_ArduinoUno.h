// ConnectedObject_ArduinoUno.h
#ifndef CONNECTEDOBJECT_ARDUINO_UNO_H
#define CONNECTEDOBJECT_ARDUINO_UNO_H

#include "../../ConnectedObject.h"
#include "../../modules/Config/ConfigManager.h"
#include "../../modules/Connectivity/implementations/ArduinoUno/ConnectivityManager_ArduinoUno.h"
#include "../../modules/Entities/EntitiesManager.h"
#include "../../modules/Messages/MessagesManager.h"
#include "../../modules/Config/DTO/FactorySettings.h"

class ConnectedObject_ArduinoUno : public ConnectedObject<ConfigManager, ConnectivityManager_ArduinoUno, EntitiesManager, MessagesManager> {
public:
    ConnectedObject_ArduinoUno(FactorySettings& settings) 
        : ConnectedObject<ConfigManager, ConnectivityManager_ArduinoUno, EntitiesManager, MessagesManager>(settings) 
    {
    }
};

#endif
