#ifndef ELECTRONSAILGENERATOR_H
#define ELECTRONSAILGENERATOR_H

#include "abstractgenerator.h"

class ElectronSailGenerator: public AbstractGenerator
{
public:
    ElectronSailGenerator(const std::string & name, const std::string & description, IShip *ship,
                          const int & mutliplier);
private:
    int multiplier;
};

#endif // ELECTRONSAILGENERATOR_H
