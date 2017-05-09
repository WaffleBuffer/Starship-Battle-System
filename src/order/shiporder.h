#ifndef SHIPORDER_H
#define SHIPORDER_H

class IShip;
class ShipControl;

class ShipOrder
{
public:
    ShipOrder(IShip *ship);
    virtual ~ShipOrder();
    virtual void applyOrder() = 0;
    ShipControl *getControl();
private:
    IShip *ship;
    ShipControl *control;
};

#endif // SHIPORDER_H
