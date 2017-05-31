#ifndef HULLLEVEL_H
#define HULLLEVEL_H

/**
 * @file hulllevel.h
 */

#include "../fileManager/saveHandler/xmlsavable.h"
#include <string>

/**
 * @brief The hullLevel class. A hull level of a ship's hull.
 */
class HullLevel: public XMLSavable
{
public:
    /**
     * @brief hullLevel The constructor.
     * @param hullQuality The hull quality: the difficulty to destroy this level of hull.
     */
    HullLevel(const int& hullQuality);

    virtual ~HullLevel();

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

    /**
     * @brief getRootName Get the hull level XML root name.
     * @return The hull XML root name.
     */
    static const char *getRootName();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a Hull from an XML node
     * @param root The xml node that should contain the Hull informations.
     * @return The created Hull.
     */
    static HullLevel*loadFromXML(const pugi::xml_node &root);

private:
    /**
     * @brief hullQuality The difficulty to destroy this level. The damage needs to roll higher or equal to this to destroy it.
     */
    int hullQuality;

    /**
     * @brief rootName The name of the XML root for a hull level.
     */
    static const char* rootName;
};

#endif // HULLLEVEL_H
