#ifndef HULL_H
#define HULL_H

/**
 * @file abstracthull.h
 */

#include "../utils/observer.h"

#include <string>

class IShip;

/**
 * @brief The AbstractHull class. Abstract class.
 */
class AbstractHull: public Observer
{
public:
    /**
     * @brief AbstractHull The constructor.
     * @param maxPoints The maximum number of hull points.
     * @param ship The ship of this hull.
     */
    AbstractHull(const int & maxPoints, IShip *ship);
    /**
     * @brief toString Get the string representaton.
     * @return The string representation.
     */
    std::string toString();
    /**
     * @brief setCurrentPoints Set the current number of hull points.
     * @param points The number of current points to set.
     */
    void setCurrentPoints(const int & points);
    /**
     * @brief getCurrentPoints Get the current number of hull points.
     * @return The current number of hull points.
     */
    int getCurrentPoints();
    /**
     * @brief getShip Get the ship of the hull.
     * @return The ship of the hull.
     */
    IShip *getShip();
private:
    /**
     * @brief maxPoints The maximum number of hull points.
     */
    int maxPoints;
    /**
     * @brief currentPoints The current number of hull points
     */
    int currentPoints;
    /**
     * @brief ship The ship of the hull.
     */
    IShip *ship;
};

#endif // HULL_H
