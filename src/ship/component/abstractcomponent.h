#ifndef ABSTRACTCOMPONENT_H
#define ABSTRACTCOMPONENT_H

/**
 * @file abstractcomponent.h
 */

#include "icomponent.h"

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
};

#endif // ABSTRACTCOMPONENT_H
