#ifndef SHIPORDER_H
#define SHIPORDER_H

#include <string>

/**
 * @file shiporder.h
 */

class IShip;
class ShipControl;

/**
 * @brief The ShipOrder class. An order that can be set to a ship.
 *        This class is abstract.
 */
class ShipOrder
{
public:
    /**
     * @brief ShipOrder The constructor.
     * @param ship The ship which order apply to.
     */
    ShipOrder(IShip *ship);
    virtual ~ShipOrder();
    /**
     * @brief applyOrder Apply this order. Virtual
     */
    virtual void applyOrder() = 0;
    /**
     * @brief getControl Get the ship control.
     * @return The ship control.
     */
    ShipControl *getControl();
    /**
     * @brief toString Get the string representation. Pure virtual
     * @return Get the string representation.
     */
    virtual std::string toString() = 0;
    /**
     * @brief getShip Get the ship.
     * @return The ship
     */
    IShip *getShip();
private:
    /**
     * @brief ship The ship which order applys to
     */
    IShip *ship;
    /**
     * @brief control The ship's control.
     */
    ShipControl *control;
};

#endif // SHIPORDER_H
