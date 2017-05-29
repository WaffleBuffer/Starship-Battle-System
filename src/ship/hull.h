#ifndef HULL_H
#define HULL_H

/**
 * @file hull.h
 */

#include "../utils/observer.h"
#include "component/abstractcomponent.h"

#include <string>
#include <vector>

class IShip;
class HullLevel;

/**
 * @brief The AbstractHull class. Abstract class.
 */
class Hull: public Observer, public AbstractComponent
{
public:
    /**
     * @brief AbstractHull The constructor.
     * @param maxPoints The maximum number of hull points.
     * @param ship The ship of this hull.
     */
    Hull(IShip *ship, std::vector<HullLevel*> *hullLevels);
    ~Hull();
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
     * @brief notify Notify this. Used to know when damage are taken.
     * @param origin The origin (the ship).
     * @param arg The argument (The damage object).
     */
    void notify(Observable *origin, MyObject *arg) override;

    /**
     * @brief deteriorateHull Destroy one level of hull.
     */
    void deteriorateHull();
private:
    /**
     * @brief hullLevels All the levels of the hull.
     */
    std::vector<HullLevel*> *hullLevels;

    /**
     * @brief currentLevel The current hull level.
     */
    HullLevel *currentLevel;
    /**
     * @brief currentLevelIndex The index of the current hull level.
     */
    size_t currentLevelIndex;
};

#endif // HULL_H
