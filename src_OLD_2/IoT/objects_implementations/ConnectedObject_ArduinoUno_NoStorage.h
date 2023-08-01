#ifndef CONNECTED_OBJECT_ARDUINO_UNO_NOSTORAGE_H
#define CONNECTED_OBJECT_ARDUINO_UNO_NOSTORAGE_H

#include "../GenericConnectedObject.h"
#include "../modules/Config/implementations/FactorySettingsNoStorage/ConfigsManager_FactorySettingsNoStorage.h"

template<class TDeviceConfig, class THardwareConfig>
class ConnectedObject_ArduinoUno_NoStorage : public GenericConnectedObject<ConfigsManager_FactorySettingsNoStorage<TDeviceConfig, THardwareConfig>> {
};

#endif // CONNECTED_OBJECT_ARDUINO_UNO_NOSTORAGE_H
