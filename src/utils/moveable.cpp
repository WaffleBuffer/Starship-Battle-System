#include "vectorialmovement.h"
#include "constants.cpp"

#include <cmath>
#include <stdexcept>

Moveable::Moveable(VectorialMovement *movement)
    :movement(movement){

    this->movement->setMovingObject(this);
}

Moveable::~Moveable()
{
    delete (this->movement);
}

VectorialMovement *Moveable::getMovement() const
{
    return movement;
}

std::string Moveable::toString()
{
    return movement->toString();
}

void Moveable::addInertia(constants::Direction direction, double distance)
{
    if(distance < 0) {
         throw std::invalid_argument("Invalid distance (< 0) when adding inertia");
    }
    // (0,0) is in upper left corner
    switch (direction) {
    case constants::NORTH:
        distance *= -1;
        break;
    case constants::SOUTH:
        break;
    default:
        throw std::invalid_argument( "Invalid direction for adding inertia" );
        break;
    }

    double newDistance = this->movement->getDistance() + distance;
    double xb = this->movement->getXPos() + newDistance * cos(this->movement->getAngle());
    double yb = this->movement->getYPos() + newDistance * sin(this->movement->getAngle());

    this->movement->setArrivingCoords(xb, yb);

    if(newDistance < 0) {
        this->movement->setgoingForward(true);
    }
    else {
        this->movement->setgoingForward(false);
    }

    // Checked in Order
    /*if(newDistance > constants::maxSpeed) {
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }
    else if (newDistance < constants::maxSpeed * -1) {
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }*/
}

void Moveable::translate(constants::Direction direction, double distance)
{
    // Checked in order
    /*if (this->movementHandler->getDistance() > constants::maxManoveurSpeed) {
        throw ShipException("Can\'t manover when inertia above " + constants::maxManoveurSpeed, this);
    }*/
    if(distance < 0) {
        throw std::invalid_argument("Invalid distance (< 0) when translating");
    }

    switch (direction) {
    case constants::NORTH:
        this->movement->setYPos(this->movement->getYPos() + distance);
        this->movement->setYOffset(this->movement->getYOffset() + distance);
        break;
    case constants::EAST:
        this->movement->setXPos(this->movement->getYPos() + distance);
        this->movement->setXOffset(this->movement->getXOffset() + distance);
        break;
    case constants::SOUTH:
        this->movement->setYPos(this->movement->getYPos() - distance);
        this->movement->setYOffset(this->movement->getYOffset() - distance);
        break;
    case constants::WEST:
        this->movement->setXPos(this->movement->getYPos() - distance);
        this->movement->setXOffset(this->movement->getXOffset() + distance);
        break;
    }

}

void Moveable::move()
{
    double newDistance = this->movement->getDistance();

    this->movement->setXPos(this->movement->getXB());
    this->movement->setYPos(this->movement->getYB());

    double xb = this->movement->getXPos() + newDistance * cos(this->movement->getAngle());
    double yb = this->movement->getYPos() + newDistance * sin(this->movement->getAngle());

    this->movement->setArrivingCoords(xb, yb);
}

void Moveable::rotate(const double &angleOffset)
{
    // Checked in order
    /*if (this->movement->getDistance() > constants::maxManoveurSpeed) {
        throw ShipException("Can\'t rotate when inertia above " + constants::maxManoveurSpeed, this);
    }*/
    this->movement->setAngle(this->movement->getAngle() + angleOffset);

    double newDistance = this->movement->getDistance();

    double xb = this->movement->getXPos() + newDistance * cos(this->movement->getAngle());
    double yb = this->movement->getYPos() + newDistance * sin(this->movement->getAngle());

    this->movement->setArrivingCoords(xb, yb);
}
