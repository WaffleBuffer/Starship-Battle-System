#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <string>

class IShip;

class IComponent
{
public:
    virtual ~IComponent() {}
    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;
    virtual IShip *getShip() = 0;
    virtual void setShip(IShip *ship) = 0;

    virtual std::string toString() = 0;
};

#endif // ICOMPONENT_H
