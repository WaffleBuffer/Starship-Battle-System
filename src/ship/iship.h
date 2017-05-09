#ifndef ISHIP_H
#define ISHIP_H

#include "../utils/constants.cpp"

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

class IShip
{
public:
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
    virtual RotationThruster *getClockWiseThruster() = 0;
    virtual RotationThruster *getCounterClockWiseThruster() = 0;

    // Components
    virtual std::vector<IComponent*> *getComponents() = 0;

    virtual std::string toString() = 0;

    virtual int generateEnergy() = 0;

    virtual std::vector<AbstractGenerator*> *getGenerators() = 0;
    virtual void addGenerator(AbstractGenerator *generator) = 0;

    virtual Sensor *getSensor() = 0;

    virtual int getInertia() = 0;

    virtual int getXPos() = 0;
    virtual int getYPos() = 0;

    virtual constants::Direction getDirection() = 0;
    virtual void addInertia(constants::Direction direction, int distance) = 0;
    virtual void translate(constants::Direction direction, int distance) = 0;
    virtual void move() = 0;
    virtual void reorientate(constants::Direction newDirection) = 0;

    virtual ShipControl *getControl() = 0;
};

#endif // ISHIP_H
