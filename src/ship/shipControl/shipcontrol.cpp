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
    // Need to do in two loops because some order create new orders that change vector size etc.
    for(size_t i = 0; i < this->orders->size(); ++i) {
        ShipOrder *order = this->orders->at(i);
        order->applyOrder();
    }
    for(auto it = this->orders->begin(); it != this->orders->end();) {
        ShipOrder *order = *it;
        it = this->orders->erase(it);
        delete(order);
    }
}

void ShipControl::endTurn()
{
    this->currentAvailableEnergy = 0;
}

IShip *ShipControl::getShip() const
{
    return ship;
}
