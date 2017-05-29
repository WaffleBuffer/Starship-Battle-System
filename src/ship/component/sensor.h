#ifndef SENSOR_H
#define SENSOR_H

/**
 * @file sensor.h
 */

#include "abstractcomponent.h"

/**
 * @brief The Sensor class. Some basic sensors.
 */
class Sensor: public AbstractComponent
{
public:
    /**
     * @brief Sensor The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxLevel The maximum level that can be obtained.
     */
    Sensor(const std::string & name, const std::string & description, IShip *ship, const int & maxLevel);

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;
private:
    /**
     * @brief currentLevel The current detection level.
     */
    int currentLevel;
    /**
     * @brief maxLevel The maximum detection level.
     */
    const int maxLevel;
};

#endif // SENSOR_H
