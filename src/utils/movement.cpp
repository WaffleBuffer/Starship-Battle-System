#include "movement.h"

Movement::Movement(Moveable *movingObject)
    :movingObject(movingObject){

}

void Movement::setMovingObject(Moveable *movingObject)
{
    this->movingObject = movingObject;
}
