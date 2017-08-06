#ifndef PROVIDEENERGYORDER_H
#define PROVIDEENERGYORDER_H

/**
 *
 */

#include "shiporder.h"

class EnergyProvidable;

/**
 * @brief The ProvideEnergyOrder class. Order to provide energy to a component.
 *        sub class of [ShipOrder](@ref ShipOrder)
 */
class ProvideEnergyOrder: public ShipOrder
{
public:
    /**
     * @brief ProvideEnergyOrder The constructor.
     * @param ship The ship wich the order applys to.
     * @param componentProvided The component to provide energy to.
     * @param energy The EU quantity to provide.
     */
    ProvideEnergyOrder(IShip *ship, EnergyProvidable *componentProvided, const int & energy);
    /**
     * @brief applyOrder Apply this order. [see ShipOrder](@ref ShipOrder)
     */
    void applyOrder() override;
    /**
     * @brief toString Get the string representation.
     * @return Get the string representation.
     */
    std::string toString() override;
    EnergyProvidable *getComponentProvided() const;

    int getEnergy() const;

    void setEnergy(int value);

private:
    /**
     * @brief energy The EU quantity to provide.
     */
    int energy;
    /**
     * @brief componentProvided The component to provide to.
     */
    EnergyProvidable *componentProvided;
};

#endif // PROVIDEENERGYORDER_H
