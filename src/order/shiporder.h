#ifndef SHIPORDER_H
#define SHIPORDER_H

#include <string>

class IShip;
class ShipControl;

class ShipOrder
{
public:
    ShipOrder(IShip *ship);
    virtual ~ShipOrder();
    virtual void applyOrder() = 0;
    ShipControl *getControl();
    virtual std::string toString() = 0;
    IShip *getShip();
private:
    IShip *ship;
    ShipControl *control;
};

#endif // SHIPORDER_H
