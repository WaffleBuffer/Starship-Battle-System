#include "iocontroller.h"
#include "../gameCore/gamecontroller.h"

IoController::IoController(GameController *gameController)
    :gameController(gameController){

}

IoController::~IoController()
{
    delete(this->gameController);
}
