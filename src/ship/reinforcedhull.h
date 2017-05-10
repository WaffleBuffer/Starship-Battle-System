#ifndef REINFORCEDHULL_H
#define REINFORCEDHULL_H

#include "abstracthull.h"

class ReinforcedHull: public AbstractHull
{
public:
    ReinforcedHull(const int & maxPoints, IShip *ship);
};

#endif // REINFORCEDHULL_H
