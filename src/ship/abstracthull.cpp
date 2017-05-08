#include "abstracthull.h"

AbstractHull::AbstractHull(const int &maxPoints)
{
    this->maxPoints = maxPoints;
    this->currentPoints = maxPoints;
}

std::string AbstractHull::toString()
{
    std::string res = "";
    res += std::to_string(this->currentPoints) + " / " + std::to_string(this->maxPoints);
    return res;
}
