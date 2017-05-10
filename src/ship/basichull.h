#ifndef BASICHULL_H
#define BASICHULL_H

#include "abstracthull.h"

class BasicHull: public AbstractHull
{
public:
    BasicHull(const int & maxPoints, IShip *ship);

    void notify(Observable *origin, MyObject *arg) override;
};

#endif // BASICHULL_H
