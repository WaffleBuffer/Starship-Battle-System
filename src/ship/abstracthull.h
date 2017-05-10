#ifndef HULL_H
#define HULL_H

#include "../utils/observer.h"

#include <string>

class IShip;

class AbstractHull: public Observer
{
public:
    AbstractHull(const int & maxPoints, IShip *ship);
    std::string toString();
    void setCurrentPoints(const int & points);
    int getCurrentPoints();
    IShip *getShip();
private:
    int maxPoints;
    int currentPoints;
    IShip *ship;
};

#endif // HULL_H
