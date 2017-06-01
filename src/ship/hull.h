#ifndef HULL_H
#define HULL_H

/**
 * @file hull.h
 */

#include "../utils/observer.h"
#include "component/abstractcomponent.h"
#include "../fileManager/saveHandler/xmlsavable.h"

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
     * @brief notify Notify this. Used to know when damage are taken.
     * @param origin The origin (the ship).
     * @param arg The argument (The damage object).
     */
    void notify(Observable *origin, MyObject *arg) override;

    /**
     * @brief deteriorateHull Destroy one level of hull.
     */
    void deteriorateHull();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a Hull from an XML node
     * @param root The xml node that should contain the Hull informations.
     * @param ship The ship that will use this hull.
     * @return The created Hull.
     */
    static Hull*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the hull XML root name.
     * @return The hull XML root name.
     */
    static const char *getRootName();

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

    /**
     * @brief rootName The name of the XML root for a Hull
     */
    static const char* rootName;
};

#endif // HULL_H
