#ifndef ABSTRACTSHIP_H
#define ABSTRACTSHIP_H

#include "iship.h"
#include "component/thruster.h"

class AbstractShip : public IShip
{
public:
    AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Thruster *forwardThruster, Thruster *backThruster,
                 Thruster *leftTThruster, Thruster *frontTThruster, Thruster *rightTThruster, Thruster *backTThruster, Thruster *clockWiseThruster,
                 Thruster *counterClockWiseThruster);
    ~AbstractShip();

    std::string getName() override;
    std::string getDescription() override;

    // Navigation thrusters
    Thruster *getForwardThruster() override;
    Thruster *getBackThruster() override;

    // Maneuver thrusters
    // Translation thrusters
    Thruster *getLeftTThruster() override;
    Thruster *getFrontTThruster() override;
    Thruster *getRightTThruster() override;
    Thruster *getBackTThruster() override;

    // Rotation thrusters
    Thruster *getClockWiseThruster() override;
    Thruster *getCounterClockWiseThruster() override;

    // Components
    std::vector<IComponent*> *getComponents() override;

    std::string toString() override;

private:
    std::string name;
    std::string description;

    AbstractHull *hull;

    // Navigation thrusters
    Thruster *forwardThruster;
    Thruster *backThruster;

    // Maneuver thrusters
    // Translation thrusters
    Thruster *leftTThruster;
    Thruster *frontTThruster;
    Thruster *rightTThruster;
    Thruster *backTThruster;

    // Rotation thrusters
    Thruster *clockWiseThruster;
    Thruster *counterClockWiseThruster;

    // Components
    std::vector<IComponent*> *components;
};

#endif // ABSTRACTSHIP_H
