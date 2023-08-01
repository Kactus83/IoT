#ifndef CONFIGS_MANAGER_ARDUINO_UNO_H
#define CONFIGS_MANAGER_ARDUINO_UNO_H

#include "../../abstract/AbstractConfigsManager.h"
#include "../modules/StorageManager/StorageManager_ArduinoUno.h"

template<class TDeviceConfig, class THardwareConfig>
class ConfigsManager_ArduinoUno : public AbstractConfigsManager<TDeviceConfig, StorageManager_ArduinoUno, THardwareConfig> {
    // In this class, the necessary specific functions could be added for ConfigsManager_ArduinoUno if needed
};

#endif // CONFIGS_MANAGER_ARDUINO_UNO_H
