#include "abstracthull.h"
#include <stdexcept>

AbstractHull::AbstractHull(const int &maxPoints, IShip *ship)
    :ship(ship){
    this->maxPoints = maxPoints;
    this->currentPoints = maxPoints;
}

std::string AbstractHull::toString()
{
    std::string res = "";
    res += std::to_string(this->currentPoints) + " / " + std::to_string(this->maxPoints);
    return res;
}

void AbstractHull::setCurrentPoints(const int &points)
{
    if (points > this->maxPoints) {
        this->currentPoints = this->maxPoints;
        throw new std::invalid_argument("Number of point to set on the hull > to max point");
    }
    else {
        this->currentPoints = points;
    }
}

int AbstractHull::getCurrentPoints()
{
    return this->currentPoints;
}

IShip *AbstractHull::getShip()
{
    return this->ship;
}
