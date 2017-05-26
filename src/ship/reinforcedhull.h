#ifndef REINFORCEDHULL_H
#define REINFORCEDHULL_H

/**
 * @file reinforcedhull.h
 */
#include "abstracthull.h"

/**
 * @brief The ReinforcedHull class. A more durable hull. Not yet implemented.
 */
class ReinforcedHull: public AbstractHull
{
public:
    /**
     * @brief ReinforcedHull The constructor.
     * @param maxPoints The maximum hit points.
     * @param ship The ship of the hull.
     */
    ReinforcedHull(const int & maxPoints, IShip *ship);
};

#endif // REINFORCEDHULL_H
