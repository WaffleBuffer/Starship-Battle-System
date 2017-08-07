#ifndef PLAYERSHIPCONTOL_H
#define PLAYERSHIPCONTOL_H

#include "shipcontrol.h"

class IoController;

class PlayerShipControl: public ShipControl
{
public:
    /**
     * @brief PlayerShipContol The constructor.
     * @param ship The ship of the controle.
     */
    PlayerShipControl(IShip *ship, IoController *ioController);
    /**
     * @brief energyDecision Ask the ship to make energy phase decisions (player).
     */
    virtual void energyDecision();

private:
    IoController *ioController;
};

#endif // PLAYERSHIPCONTOL_H
