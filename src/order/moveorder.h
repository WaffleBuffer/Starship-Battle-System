#ifndef MOVEORDER_H
#define MOVEORDER_H

#include "shiporder.h"
#include "../utils/constants.cpp"

class IShip;

/**
 * @brief The MoveOrder class. The order to tell the ship to move. Those orders are classicaly created by thrusters.
 */
class MoveOrder: public ShipOrder
{
public:
    /**
     * @brief MoveOrder The constructor.
     * @param ship The ship that will move.
     * @param direction The direction of the movement (relative to the ship).
     * @param distance The distance of the movement.
     * @param addInertia If the movement will generate inertia.
     */
    MoveOrder(IShip *ship, const constants::ShipDirection &direction, const double &distance, const bool &addInertia);

    /**
     * @brief applyOrder Apply this order.
     */
    virtual void applyOrder() override;

    /**
     * @brief toString Get the string representation.
     * @return Get the string representation.
     */
    virtual std::string toString() override;

private:
    /**
     * @brief isInertia Does this movement add inertia to the ship.
     */
    bool addInertia;

    /**
     * @brief direction The direction of the movemen.t
     */
    constants::ShipDirection direction;
    /**
     * @brief distance The distance of the movement.
     */
    double distance;
};

#endif // MOVEORDER_H
