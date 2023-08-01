#ifndef CONFIGS_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H
#define CONFIGS_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H

#include "../../abstract/AbstractConfigsManager.h"
#include "../modules/StorageManager/StorageManager_FactorySettingsNoStorage.h"

template<class TDeviceConfig, class THardwareConfig>
class ConfigsManager_FactorySettingsNoStorage : public AbstractConfigsManager<TDeviceConfig, StorageManager_FactorySettingsNoStorage, THardwareConfig> {
    // In this class, the necessary specific functions could be added for ConfigsManager_FactorySettingsNoStorage if needed
};

#endif // CONFIGS_MANAGER_FACTORY_SETTINGS_NO_STORAGE_H
