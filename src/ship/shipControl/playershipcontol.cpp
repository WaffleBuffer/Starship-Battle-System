#include "playershipcontrol.h"
#include "../../ioControler/iocontroller.h"

PlayerShipControl::PlayerShipControl(IShip *ship, IoController *ioController)
    :ShipControl(ship), ioController(ioController)
{

}

void PlayerShipControl::commandDecision()
{
    this->ioController->commandPhaseInteraction(this->getShip());
}

void PlayerShipControl::movementDecision()
{
    this->ioController->movementPhaseInteraction(this->getShip());
}
