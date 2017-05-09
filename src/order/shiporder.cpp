#include "shiporder.h"

#include "../ship/iship.h"
#include "../ship/shipcontrol.h"

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
