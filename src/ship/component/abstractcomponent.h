#ifndef ABSTRACTCOMPONENT_H
#define ABSTRACTCOMPONENT_H

/**
 * @file abstractcomponent.h
 */

#include "icomponent.h"
#include "../../utils/constants.cpp"

/**
 * @brief The AbstractComponent class. An abstract component.
 */
class AbstractComponent: public IComponent
{
public:
    /**
     * @brief AbstractComponent The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     */
    AbstractComponent(const std::string & name, const std::string & description, IShip *ship);
    virtual ~AbstractComponent();

    /**
     * @brief getName Get the component's name.
     * @return The name.
     */
    std::string getName() override;
    /**
     * @brief getDescription Get the description.
     * @return The description.
     */
    std::string getDescription() override;
    /**
     * @brief getShip Get the ship
     * @return The ship.
     */
    IShip *getShip() override;
    /**
     * @brief setShip Set the ship using this component.
     * @param ship The ship to set.
     */
    virtual void setShip(IShip *ship) override;

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    virtual std::string toString() override;

    /**
     * @brief setPart Set the part of the ship where this component is located.
     * @param value The part to set.
     */
    void setPart(const constants::shipParts &value) override;

    /**
     * @brief saveXML Save the AbstractComponent infos of an AbstractComponent.
     * @param root The root xml tag that should contain this object.
     * @param componentToLoad The AbstractComponent from which you want to save infos.
     */
    static void saveAbstractXML(pugi::xml_node &root, AbstractComponent *componentToLoad);

    /**
     * @brief loadFromXML Load AbstractComponent infos into an AbstractComponent.
     * @param root The xml node that should contain the AbstractComponent informations.
     * @param ship The ship that will use this AbstractComponent.
     * @param componentToLoad The AbstractComponent into which you want to save infos.
     */
    static void loadAbstractFromXML(IShip *ship, const pugi::xml_node &root, AbstractComponent *componentToLoad);

    /**
     * @brief getShipPart Get the ship parts where this component is located on the ship.
     * @return The ship part.
     */
     constants::shipParts getShipPart() override;

private:
    /**
     * @brief name The component's name.
     */
    std::string name;
    /**
     * @brief description The component's description.
     */
    std::string description;
    /**
     * @brief ship The component's ship.
     */
    IShip *ship;

    /**
     * @brief part The part of the ship where this component is located.
     */
    constants::shipParts part;
};

#endif // ABSTRACTCOMPONENT_H
