#ifndef ARMOR_H
#define ARMOR_H

/**
 * @file armor.h
 */

#include "../utils/observer.h"
#include "component/abstractcomponent.h"

#include <string>

/**
 * @brief The Armor class. The armor value of a ship on each side.
 */
class Armor: public Observer, public AbstractComponent
{
public:
    /**
     * @brief Armor The constructor.
     * @param bowMax The bow armor.
     * @param starMax The starboard armor.
     * @param sternMax The stern armor.
     * @param portMax The port armor.
     */
    Armor(const int & bowMax, const int & starMax, const int & sternMax, const int & portMax);
    /**
     * @brief notify Notify this armor. Used to know when damage are taken.
     * @param origin The origin object (the ship).
     * @param arg The argument (the damage object).
     */
    void notify(Observable *origin, MyObject *arg) override;
    /**
     * @brief toString Get the string representation of the armor.
     * @return The string representation;
     */
    std::string toString();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create an Armor from an XML node
     * @param root The xml node that should contain the Armor informations.
     * @param ship The ship that will use this Armor.
     * @return The created Armor.
     */
    static Armor*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the Armor XML root name.
     * @return The Armor XML root name.
     */
    static const char *getRootName();

private:
    /**
     * @brief bowMax The bow armor.
     */
    int bowMax;
    /**
     * @brief bowCurrentValue The bow current armor value.
     */
    int bowCurrentValue;
    /**
     * @brief starBoardMax The starboard armor.
     */
    int starBoardMax;
    /**
     * @brief starBoardCurrentValue The starboard current armor value.
     */
    int starBoardCurrentValue;
    /**
     * @brief sternMax The stern armor.
     */
    int sternMax;
    /**
     * @brief sternCurrentValue The stern current armor value.
     */
    int sternCurrentValue;
    /**
     * @brief portMax The port armor.
     */
    int portMax;
    /**
     * @brief portCurrentValue The current port armor value.
     */
    int portCurrentValue;

    /**
     * @brief rootName The name of the XML root for a Hull
     */
    static const char* rootName;
};

#endif // ARMOR_H
