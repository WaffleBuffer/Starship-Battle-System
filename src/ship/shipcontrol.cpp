#include "shipcontrol.h"

#include "iship.h"
#include "../order/shiporder.h"

ShipControl::ShipControl(IShip *ship)
    :ship(ship), orders(new std::vector<ShipOrder*>()), currentAvailableEnergy(0){
}

ShipControl::~ShipControl()
{
    for(size_t i = 0; i < this->orders->size(); ++i) {
        delete(this->orders->at(i));
    }
    delete(this->orders);
}

void ShipControl::addOrder(ShipOrder *order)
{
    this->orders->push_back(order);
}

std::vector<ShipOrder *> *ShipControl::getOrders()
{
    return this->orders;
}

int ShipControl::getCurrentAvailableEnergy()
{
    return this->currentAvailableEnergy;
}

void ShipControl::setCurrentAvailableEnergy(const int &energy)
{
    this->currentAvailableEnergy = energy;
}

void ShipControl::applyOrders()
{
    for(size_t i = 0; i < this->orders->size(); ++i) {
        this->orders->at(i)->applyOrder();
    }
}
