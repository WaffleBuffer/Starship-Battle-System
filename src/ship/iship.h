#ifndef ISHIP_H
#define ISHIP_H

#include "../utils/constants.cpp"
#include "../utils/observable.h"
#include "damageable.h"
#include "../utils/moveable.h"

#include <string>
#include <vector>

class IComponent;
class NavThruster;
class TranslationThruster;
class RotationThruster;
class AbstractHull;
class AbstractGenerator;
class Sensor;
class ShipControl;
class Observer;
class Damage;
class VectorialMovement;

class IShip: public Observable, public Damageable, public Moveable
{
public:
    IShip(VectorialMovement *movement);
    virtual ~IShip() {}

    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;

    // Navigation thrusters
    virtual NavThruster *getForwardThruster() = 0;
    virtual NavThruster *getBackThruster() = 0;

    // Maneuver thrusters
    // Translation thrusters
    virtual TranslationThruster *getLeftTThruster() = 0;
    virtual TranslationThruster *getFrontTThruster() = 0;
    virtual TranslationThruster *getRightTThruster() = 0;
    virtual TranslationThruster *getBackTThruster() = 0;

    // Rotation thrusters
    virtual RotationThruster *getRotationThruster() = 0;

    // Components
    virtual std::vector<IComponent*> *getComponents() = 0;

    virtual std::string toString() = 0;

    virtual int generateEnergy() = 0;

    virtual std::vector<AbstractGenerator*> *getGenerators() = 0;
    virtual void addGenerator(AbstractGenerator *generator) = 0;

    virtual Sensor *getSensor() = 0;

    virtual ShipControl *getControl() = 0;

    virtual void addDamageObserver(Observer *observer) = 0;


    virtual void addAfterDamageObserver(Observer *observer) = 0;

    virtual void destroy() = 0;
};

#endif // ISHIP_H
