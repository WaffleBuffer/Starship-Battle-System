#ifndef THRUSTER_H
#define THRUSTER_H

#include "abstractcomponent.h"

class Thruster: public AbstractComponent
{
public:
    Thruster();
private:
    int maxEnergy;
};

#endif // THRUSTER_H
