#ifndef ABSTRACTSHIP_H
#define ABSTRACTSHIP_H

#include "abstracthull.h"
#include "iship.h"
#include "component/thruster.h"

#include <string>

using namespace std;

class AbstractShip : public IShip
{
public:
    AbstractShip();
    string name;
    string description;

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
};

#endif // ABSTRACTSHIP_H
