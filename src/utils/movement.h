#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "moveable.h"

class Movement
{
public:
    Movement(Moveable *movingObject);
    virtual ~Movement() {}

    Moveable *getMovingObject();
    void setMovingObject(Moveable *movingObject);

    virtual double getDistance() = 0;
    virtual void setArrivingCoords(const double &xb, const double &yb) = 0;

private:
    Moveable *movingObject;
};

#endif // MOVEMENT_H
