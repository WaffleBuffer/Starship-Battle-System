#include "shipcontrol.h"

#include "../iship.h"
#include "../../order/shiporder.h"

ShipControl::ShipControl(IShip *ship)
    :ship(ship), currentAvailableEnergy(0), orders(new std::vector<ShipOrder*>()){
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

unsigned int ShipControl::getCurrentAvailableEnergy()
{
    return this->currentAvailableEnergy;
}

void ShipControl::setCurrentAvailableEnergy(const int &energy)
{
    (energy < 0) ? this->currentAvailableEnergy = 0 : this->currentAvailableEnergy = energy;
}

void ShipControl::applyOrders()
{
    for(size_t i = 0; i < this->orders->size(); ++i) {
        this->orders->at(i)->applyOrder();
    }
    for(size_t i = 0; i < this->orders->size(); ++i) {
        delete(this->orders->at(i));
    }
    delete(this->orders);
    this->orders = new std::vector<ShipOrder*>();
}

void ShipControl::endTurn()
{
    this->currentAvailableEnergy = 0;
}

IShip *ShipControl::getShip() const
{
    return ship;
}
