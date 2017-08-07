#include "shiporder.h"

#include "../ship/iship.h"

ShipOrder::ShipOrder(IShip *ship)
    :ship(ship), control(ship->getControl()){

}

ShipOrder::~ShipOrder()
{

}

ShipControl *ShipOrder::getControl()
{
    return this->control;
}

IShip *ShipOrder::getShip()
{
    return this->ship;
}
