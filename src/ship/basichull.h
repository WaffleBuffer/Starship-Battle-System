#ifndef BASICHULL_H
#define BASICHULL_H

/**
 * @file basichull.h
 */

#include "abstracthull.h"

/**
 * @brief The BasicHull class. The basic hull of a ship with no particular resistance.
 */
class BasicHull: public AbstractHull
{
public:
    /**
     * @brief BasicHull The constructor.
     * @param maxPoints The maximum hull point.
     * @param ship The ship for this hull.
     */
    BasicHull(const int & maxPoints, IShip *ship);

    /**
     * @brief notify Notify this. Used to know when damage are taken.
     * @param origin The origin (the ship).
     * @param arg The argument (The damage object).
     */
    void notify(Observable *origin, MyObject *arg) override;
};

#endif // BASICHULL_H
