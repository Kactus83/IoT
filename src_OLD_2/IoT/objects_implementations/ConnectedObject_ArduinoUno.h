#ifndef CONNECTED_OBJECT_ARDUINO_UNO_H
#define CONNECTED_OBJECT_ARDUINO_UNO_H

#include "../GenericConnectedObject.h"
#include "../modules/Config/implementations/ArduinoUno/ConfigsManager_ArduinoUno.h"

template<class TDeviceConfig, class THardwareConfig>
class ConnectedObject_ArduinoUno : public GenericConnectedObject<ConfigsManager_ArduinoUno<TDeviceConfig, THardwareConfig>> {
};

#endif // CONNECTED_OBJECT_ARDUINO_UNO_H
