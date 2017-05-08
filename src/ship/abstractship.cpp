#include "abstractship.h"
#include "component/abstractgenerator.h"
#include "component/sensor.h"
#include "abstracthull.h"
#include "component/translationthruster.h"
#include "component/navthruster.h"
#include "component/rotationthruster.h"
#include "../utils/utils.cpp"

#include <iostream>
#include <string>
#include <stdexcept>

AbstractShip::AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
                           TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
                           RotationThruster *clockWiseThruster, RotationThruster *counterClockWiseThruster){

    this->name = name;
    this->description = description;
    this->xPos = 0;
    this->yPos = 0;
    this->direction = constants::NORTH;
    this->inertia = 0;

    this->hull = hull;
    this->sensor = sensor;
    sensor->setShip(this);

    // Navigation thrusters
    this->forwardThruster = forwardThruster;
    forwardThruster->setShip(this);
    forwardThruster->setFacingDirection(constants::NORTH);
    this->backThruster = backThruster;
    backThruster->setShip(this);
    backThruster->setFacingDirection(constants::SOUTH);

    // Maneuver thrusters
    // Translation thrusters
    this->leftTThruster = leftTThruster;
    leftTThruster->setShip(this);
    leftTThruster->setFacingDirection(constants::WEST);
    this->frontTThruster = frontTThruster;
    frontTThruster->setShip(this);
    frontTThruster->setFacingDirection(constants::NORTH);
    this->rightTThruster = rightTThruster;
    rightTThruster->setShip(this);
    rightTThruster->setFacingDirection(constants::EAST);
    this->backTThruster = backTThruster;
    backTThruster->setShip(this);
    backTThruster->setFacingDirection(constants::SOUTH);

    // Rotation thrusters
    this->clockWiseThruster = clockWiseThruster;
    clockWiseThruster->setShip(this);
    clockWiseThruster->setDirection(constants::CLOCKWISE);
    this->counterClockWiseThruster = counterClockWiseThruster;
    counterClockWiseThruster->setShip(this);
    counterClockWiseThruster->setDirection(constants::COUNTER_CLOCKWISE);

    // Components
    this->components = new std::vector<IComponent*>();

    this->generators = new std::vector<AbstractGenerator*>();
}

AbstractShip::~AbstractShip() {
    delete(this->hull);
    delete(this->sensor);

    // Navigation thrusters
    delete(this->forwardThruster);
    delete(this->backThruster);

    // Maneuver thrusters
    // Translation thrusters
    delete(this->leftTThruster);
    delete(this->frontTThruster);
    delete(this->rightTThruster);
    delete(this->backTThruster);

    // Rotation thrusters
    delete(this->clockWiseThruster);
    delete(this->counterClockWiseThruster);

    for(size_t i = 0; i < this->generators->size(); ++i) {
        delete(this->generators->at(i));
    }

    delete(this->generators);

    for(size_t i = 0; i < this->components->size(); ++i) {
        delete(this->components->at(i));
    }

    delete(this->components);
}

std::string AbstractShip::getName(){
    return this->name;
}

std::string AbstractShip::getDescription() {
    return this->description;
}

// Navigation thrusters
NavThruster *AbstractShip::getForwardThruster() {
    return this->forwardThruster;
}

NavThruster *AbstractShip::getBackThruster() {
    return this->backThruster;
}

// Maneuver thrusters
// Translation thrusters
TranslationThruster *AbstractShip::getLeftTThruster() {
    return this->leftTThruster;
}

TranslationThruster *AbstractShip::getFrontTThruster() {
    return this->frontTThruster;
}

TranslationThruster *AbstractShip::getRightTThruster() {
    return this->rightTThruster;
}

TranslationThruster *AbstractShip::getBackTThruster() {
    return this->backTThruster;
}

// Rotation thrusters
RotationThruster *AbstractShip::getClockWiseThruster() {
    return this->clockWiseThruster;
}

RotationThruster *AbstractShip::getCounterClockWiseThruster() {
    return this->counterClockWiseThruster;
}

// Components
std::vector<IComponent*> *AbstractShip::getComponents(){
    return this->components;
}

std::string AbstractShip::toString()
{
    std::string res = "";
    res += this->getName() + "\n";
    res += this->getDescription() + "\n";

    res += "Position : {" + std::to_string(this->getXPos()) + ", " + std::to_string(this->getYPos()) + "}\n";
    res += "Inertia : " + std::to_string(this->getInertia()) + "\n";
    res += "Direction : " + utils::getDirectionStr(this->getDirection()) + "\n";

    res += "hull : " + this->hull->toString() + "\n";

    res += "sensor : " + this->sensor->toString() + "\n";

    res += "thrusters :\n";
    res += "F " + this->getForwardThruster()->toString() + "\n";
    res += "B " + this->getBackThruster()->toString() + "\n";
    res += "LT " + this->getLeftTThruster()->toString() + "\n";
    res += "FT " + this->getFrontTThruster()->toString() + "\n";
    res += "RT " + this->getRightTThruster()->toString() + "\n";
    res += "BT " + this->getBackTThruster()->toString() + "\n";
    res += "CR " + this->getClockWiseThruster()->toString() + "\n";
    res += "CCR " + this->getCounterClockWiseThruster()->toString() + "\n";

    res += "generators : \n";

    for(size_t i = 0; i < this->generators->size(); ++i) {
        res += this->generators->at(i)->toString() + "\n";
    }

    res += "components : \n";

    for(size_t i = 0; i < this->components->size(); ++i) {
        res += this->components->at(i)->toString() + "\n";
    }

    return res;
}

int AbstractShip::generateEnergy()
{
    int energy = 0;
    for(size_t i = 0; i < this->generators->size(); ++i) {
        energy += this->generators->at(i)->generateEnergy();
    }

    return energy;
}

std::vector<AbstractGenerator *> *AbstractShip::getGenerators()
{
    return this->generators;
}

void AbstractShip::addGenerator(AbstractGenerator *generator)
{
    this->generators->push_back(generator);
    generator->setShip(this);
}

Sensor *AbstractShip::getSensor()
{
    return this->sensor;
}

int AbstractShip::getInertia()
{
    return this->inertia;
}

int AbstractShip::getXPos()
{
    return this->xPos;
}

int AbstractShip::getYPos()
{
    return this->yPos;
}

constants::Direction AbstractShip::getDirection()
{
    return this->direction;
}

void AbstractShip::addInertia(constants::Direction direction, int distance)
{
    std::cout << utils::getDirectionStr(direction) << " " << std::to_string(distance) << std::endl;
    switch (direction) {
    case constants::NORTH:
        this->inertia -= distance;
        break;
    case constants::SOUTH:
        this->inertia += distance;
        break;
    default:
        throw std::invalid_argument( "Invalid direction for inertia" );
        break;
    }

    if(this->inertia > constants::maxSpeed) {
        this->inertia = constants::maxSpeed;
    }
    else if (this->inertia < constants::maxSpeed * -1) {
        this->inertia = constants::maxSpeed * -1;
    }
}

void AbstractShip::translate(constants::Direction direction, int distance)
{
    switch (direction) {
    case constants::NORTH:
        this->yPos += distance;
        break;
    case constants::EAST:
        this->xPos += distance;
        break;
    case constants::SOUTH:
        this->yPos -= distance;
        break;
    case constants::WEST:
        this->xPos -= distance;
        break;
    }

}

void AbstractShip::move()
{
    switch (this->direction) {
    case constants::NORTH:
        this->yPos += (this->inertia > 0 ? this->inertia : 0 - this->inertia);
        break;
    case constants::EAST:
        this->xPos += (this->inertia > 0 ? this->inertia : 0 - this->inertia);
        break;
    case constants::SOUTH:
        this->yPos -= (this->inertia > 0 ? this->inertia : 0 - this->inertia);
        break;
    case constants::WEST:
        this->xPos -= (this->inertia > 0 ? this->inertia : 0 - this->inertia);
        break;
    }
}

void AbstractShip::reorientate(constants::Direction newDirection)
{
    this->direction = newDirection;
}
