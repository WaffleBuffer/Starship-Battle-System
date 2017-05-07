#ifndef THRUSTER_H
#define THRUSTER_H

#include "abstractcomponent.h"

class IShip;

class Thruster: public AbstractComponent {
public:
    Thruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    Thruster(Thruster *model);

    int getMaxEnergy();
private:
    int maxEnergy;
};

#endif // THRUSTER_H
