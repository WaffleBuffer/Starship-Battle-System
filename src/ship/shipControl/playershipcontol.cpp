#include "playershipcontrol.h"
#include "../../ioControler/iocontroller.h"

PlayerShipControl::PlayerShipControl(IShip *ship, IoController *ioController)
    :ShipControl(ship), ioController(ioController)
{

}

void PlayerShipControl::energyDecision()
{
    this->ioController->energyPhaseInteraction(this->getShip());
}
