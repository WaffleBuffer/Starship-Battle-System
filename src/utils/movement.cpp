#include "movement.h"

Movement::Movement(Moveable *movingObject, const char *rootName)
    :XMLSavable(rootName), movingObject(movingObject){

}

void Movement::setMovingObject(Moveable *movingObject)
{
    this->movingObject = movingObject;
}
