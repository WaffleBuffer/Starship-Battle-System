#ifndef ABSTRACTCOMPONENT_H
#define ABSTRACTCOMPONENT_H

#include "icomponent.h"

class AbstractComponent: public IComponent
{
public:
    AbstractComponent(const std::string & name, const std::string & description, IShip *ship);
    virtual ~AbstractComponent();

    std::string getName() override;
    std::string getDescription() override;
    IShip *getShip() override;
    void setShip(IShip *ship) override;

    virtual std::string toString() override;
private:
    std::string name;
    std::string description;
    IShip *ship;
};

#endif // ABSTRACTCOMPONENT_H
