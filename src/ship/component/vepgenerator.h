#ifndef VEPGENERATOR_H
#define VEPGENERATOR_H

#include "abstractgenerator.h"

class VEPGenerator: public AbstractGenerator
{
public:
    VEPGenerator(const std::string & name, const std::string & description, IShip *ship, const int & energyDelivered);
private:
    int energyDelivered;
};

#endif // VEPGENERATOR_H
