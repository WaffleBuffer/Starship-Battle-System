#ifndef ISHIP_H
#define ISHIP_H

#include "component/abstractcomponent.h"
#include "abstracthull.h"

#include <string>
#include <vector>

class IComponent;
class Thruster;

class IShip
{
public:
    virtual ~IShip() {}

    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;

    // Navigation thrusters
    virtual Thruster *getForwardThruster() = 0;
    virtual Thruster *getBackThruster() = 0;

    // Maneuver thrusters
    // Translation thrusters
    virtual Thruster *getLeftTThruster() = 0;
    virtual Thruster *getFrontTThruster() = 0;
    virtual Thruster *getRightTThruster() = 0;
    virtual Thruster *getBackTThruster() = 0;

    // Rotation thrusters
    virtual Thruster *getClockWiseThruster() = 0;
    virtual Thruster *getCounterClockWiseThruster() = 0;

    // Components
    virtual std::vector<IComponent*> *getComponents() = 0;

    virtual std::string toString() = 0;
};

#endif // ISHIP_H
