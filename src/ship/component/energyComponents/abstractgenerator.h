#ifndef ABSTRACTGENERATOR_H
#define ABSTRACTGENERATOR_H

#include "../abstractcomponent.h"

class AbstractGenerator: public AbstractComponent
{
public:
    AbstractGenerator(const std::string & name, const std::string & description, IShip *ship);
    virtual ~AbstractGenerator();

    virtual int generateEnergy() = 0;
private:
};

#endif // ABSTRACTGENERATOR_H
