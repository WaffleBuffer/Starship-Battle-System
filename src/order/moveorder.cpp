#include "moveorder.h"
#include "../ship/iship.h"
#include "../utils/utils.cpp"

#include <string>
#include <iomanip>
#include <sstream>

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
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << this->distance;
    std::string res = "Move for " + stream.str() + " to " + utils::shipDirectionToStr(this->direction);
    if(this->addInertia) {
        res += " with inertia";
    }
    return res;
}
