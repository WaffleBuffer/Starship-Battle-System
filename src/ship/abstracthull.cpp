#include "abstracthull.h"

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
    this->currentPoints = points;
}

int AbstractHull::getCurrentPoints()
{
    return this->currentPoints;
}

IShip *AbstractHull::getShip()
{
    return this->ship;
}
