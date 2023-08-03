#ifndef HARDWARE_DEVICES_MODULES_CONTAINER_INTERFACE_H
#define HARDWARE_DEVICES_MODULES_CONTAINER_INTERFACE_H

#include "HardwareDeviceModuleInterface.h"

class HardwareDevicesModulesContainerInterface
{
public:
    virtual ~HardwareDevicesModulesContainerInterface() {}

    // Renvoie le nombre de modules dans le conteneur
    virtual int moduleCount() const = 0;

    // Renvoie un pointeur vers le module à l'index spécifié
    virtual HardwareDeviceModuleInterface* getModule(int index) = 0;

    // Renvoie le nombre total d'entités dans tous les modules
    virtual int totalEntityCount() const = 0;

    // Renvoie un pointeur vers l'entité à l'index global spécifié
    virtual EntityInterface* getEntity(int globalIndex) = 0;

    // Méthode pour configurer tous les modules
    virtual void setupModules() = 0;

    // Méthode pour gérer la boucle de tous les modules
    virtual void loopModules() = 0;
};

#endif // HARDWARE_DEVICES_MODULES_CONTAINER_INTERFACE_H
