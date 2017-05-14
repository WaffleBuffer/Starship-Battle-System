#ifndef SHIPCONTROL_H
#define SHIPCONTROL_H

#include <vector>

class IShip;
class ShipOrder;

class ShipControl
{
public:
    ShipControl(IShip *ship);
    ~ShipControl();
    void addOrder(ShipOrder *order);
    std::vector<ShipOrder*> *getOrders();
    int getCurrentAvailableEnergy();
    void setCurrentAvailableEnergy(const int & energy);
    void applyOrders();
    void endTurn();
private:
    IShip *ship;
    int currentAvailableEnergy;
    std::vector<ShipOrder*> *orders;
};

#endif // SHIPCONTROL_H
