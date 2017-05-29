#ifndef HULLLEVEL_H
#define HULLLEVEL_H

/**
 * @file hulllevel.h
 */

#include <string>

/**
 * @brief The hullLevel class. A hull level of a ship's hull.
 */
class HullLevel
{
public:
    /**
     * @brief hullLevel The constructor.
     * @param hullQuality The hull quality: the difficulty to destroy this level of hull.
     */
    HullLevel(const int& hullQuality);

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString();

    /**
     * @brief getHullQuality Get the difficulty to destroy this level. The damage needs to roll higher or equal to this to destroy it.
     * @return The difficulty to destroy this level. The damage needs to roll higher or equal to this to destroy it.
     */
    int getHullQuality() const;

private:
    /**
     * @brief hullQuality The difficulty to destroy this level. The damage needs to roll higher or equal to this to destroy it.
     */
    int hullQuality;
};

#endif // HULLLEVEL_H
