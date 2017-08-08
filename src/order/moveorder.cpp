#include "moveorder.h"
#include "../ship/iship.h"
#include "../utils/utils.cpp"

#include <string>

MoveOrder::MoveOrder(IShip *ship, const constants::ShipDirection &direction, const double &distance, const bool &addInertia)
    :ShipOrder(ship), addInertia(addInertia), direction(direction), distance(distance) {

}

void MoveOrder::applyOrder()
{
    this->getShip()->translate(this->direction, this->distance);
    if(this->addInertia) {
        this->getShip()->addInertia(this->direction, this->distance);
    }
}

std::string MoveOrder::toString()
{
    std::string res = "Move for " + std::to_string(this->distance) + " to " + utils::shipDirectionToStr(this->direction);
    if(this->addInertia) {
        res += " with inertia";
    }
    return res;
}
