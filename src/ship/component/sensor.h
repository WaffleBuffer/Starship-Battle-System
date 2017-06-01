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

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a Sensor from an XML node
     * @param root The xml node that should contain the Sensor informations.
     * @param ship The ship that will use this sensor.
     * @return The created Sensor.
     */
    static Sensor*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the sensor XML root name.
     * @return The hull XML root name.
     */
    static const char *getRootName();

private:
    /**
     * @brief currentLevel The current detection level.
     */
    int currentLevel;
    /**
     * @brief maxLevel The maximum detection level.
     */
    const int maxLevel;

    /**
     * @brief rootName The name of the XML root for a Sensor
     */
    static const char* rootName;
};

#endif // SENSOR_H
