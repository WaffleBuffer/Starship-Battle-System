#ifndef SHIPCONTROL_H
#define SHIPCONTROL_H

/**
 * @file shipcontrol.h
 */

#include <vector>

class IShip;
class ShipOrder;

/**
 * @brief The ShipControl class. The object to add input to a ship.
 */
class ShipControl
{
public:
    /**
     * @brief ShipControl The constructor.
     * @param ship The ship of the controle.
     */
    ShipControl(IShip *ship);
    ~ShipControl();
    /**
     * @brief addOrder Add an order to the ship.
     * @param order The order to add.
     */
    void addOrder(ShipOrder *order);
    /**
     * @brief getOrders Get the unexecuted orders.
     * @return The unexecuted orders.
     */
    std::vector<ShipOrder*> *getOrders();
    /**
     * @brief getCurrentAvailableEnergy Get the current available Energy Unit (EU). To add some, use generate energy from the ship.
     * @return The current available energy.
     */
    unsigned int getCurrentAvailableEnergy();
    /**
     * @brief setCurrentAvailableEnergy Set the current available energy.
     * @param energy The energy to set.
     */
    void setCurrentAvailableEnergy(const int & energy);
    /**
     * @brief applyOrders Apply all unexecuted orders.
     */
    void applyOrders();
    /**
     * @brief endTurn Reset what need to be reset in order to end a turn.
     */
    void endTurn();

    /**
     * @brief energyDecision Ask the ship to make energy phase decisions (ia or player).
     */
    virtual void energyDecision() = 0;
    IShip *getShip() const;

private:
    /**
     * @brief ship The ship of the control.
     */
    IShip *ship;
    /**
     * @brief currentAvailableEnergy The current amount of Energy Unit (EU).
     */
    unsigned int currentAvailableEnergy;
    /**
     * @brief orders The unexecuted orders.
     */
    std::vector<ShipOrder*> *orders;
};

#endif // SHIPCONTROL_H
