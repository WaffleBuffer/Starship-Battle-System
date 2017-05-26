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

void Moveable::addInertia(constants::ShipDirection direction, double distance)
{
    if(distance < 0) {
         throw std::invalid_argument("Invalid distance (< 0) when adding inertia");
    }
    // (0,0) is in upper left corner
    switch (direction) {
    case constants::BOW:
        break;
    case constants::STERN:
        distance *= -1;
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
        this->movement->setgoingForward(false);
    }
    else {
        this->movement->setgoingForward(true);
    }

    // Checked in Order
    /*if(newDistance > constants::maxSpeed) {
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }
    else if (newDistance < constants::maxSpeed * -1) {
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }*/
}

void Moveable::translate(constants::ShipDirection direction, double distance)
{
    // Checked in order
    /*if (this->movementHandler->getDistance() > constants::maxManoveurSpeed) {
        throw ShipException("Can\'t manover when inertia above " + constants::maxManoveurSpeed, this);
    }*/
    if(distance < 0) {
        throw std::invalid_argument("Invalid distance (< 0) when translating");
    }

    double xb, yb;

    double x = this->movement->getXPos();
    double y = this->movement->getYPos();

    double xAngleOffset = 0;
    double yAngleOffset = 0;

    switch (direction) {
    // If we put relative angle, we use trigonometric circle to offset the angle
    case constants::BOW:
        xAngleOffset = 0;
        x = this->movement->getXPos() + distance * cos(this->movement->getAngle() + xAngleOffset);
        break;
    case constants::STARBOARD:
        yAngleOffset = M_PI / 2;
        y = this->movement->getYPos() + distance * sin(this->movement->getAngle() + yAngleOffset);
        break;
    case constants::STERN:
        xAngleOffset = M_PI;
        x = this->movement->getXPos() + distance * cos(this->movement->getAngle() + xAngleOffset);
        break;
    case constants::PORT:
        yAngleOffset = 3 * M_PI / 2;
        y = this->movement->getYPos() + distance * sin(this->movement->getAngle() + yAngleOffset);
        break;
    }

    this->movement->setXPos(x);
    this->movement->setYPos(y);

    xb = this->movement->getXPos() + this->getMovement()->getDistance() * cos(this->movement->getAngle());
    yb = this->movement->getYPos() + this->getMovement()->getDistance() * sin(this->movement->getAngle());

    this->movement->setArrivingCoords(xb, yb);

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
