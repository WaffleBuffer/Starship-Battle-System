#include "abstractship.h"
#include "component/energyComponents/abstractgenerator.h"
#include "component/sensor.h"
#include "abstracthull.h"
#include "component/translationthruster.h"
#include "component/navthruster.h"
#include "component/rotationthruster.h"
#include "../utils/utils.cpp"
#include "../utils/shipexception.h"
#include "shipcontrol.h"
#include "../utils/observer.h"
#include "../ship/damage.h"
#include "armor.h"
#include "component/energyComponents/stagegenerator.h"

#include <iostream>
#include <string>
#include <stdexcept>

AbstractShip::AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
                           TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
                           RotationThruster *clockWiseThruster, RotationThruster *counterClockWiseThruster)
    :armor(armor), stageGenerators(new std::vector<StageGenerator*>()), damageObservers(new std::vector<Observer *>()), afterDamageObservers(new std::vector<Observer *>()){

    this->name = name;
    this->description = description;
    this->xPos = 0;
    this->yPos = 0;
    this->direction = constants::NORTH;
    this->inertia = 0;
    this->control = new ShipControl(this);

    this->hull = hull;
    this->addAfterDamageObserver(this->hull);
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
    delete(this->control);
    delete(this->armor);

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
    delete(this->stageGenerators);

    for(size_t i = 0; i < this->components->size(); ++i) {
        delete(this->components->at(i));
    }

    delete(this->components);

    delete(this->damageObservers);
    delete(this->afterDamageObservers);
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

    res += "armor : " + this->armor->toString() + "\n";
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

    this->control->setCurrentAvailableEnergy(energy);
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
    StageGenerator *stageGenerator = dynamic_cast<StageGenerator*>(generator);
    if(stageGenerator != NULL) {
        this->stageGenerators->push_back(stageGenerator);
    }
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
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }
    else if (this->inertia < constants::maxSpeed * -1) {
        throw ShipException("Ship speed above limit but not implemented yer", this);
    }
}

void AbstractShip::translate(constants::Direction direction, int distance)
{
    if (this->inertia > constants::maxManoveurSpeed) {
        throw ShipException("Can\'t manover when inertia above " + constants::maxManoveurSpeed, this);
    }
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
    if (this->inertia > constants::maxManoveurSpeed) {
        throw ShipException("Can\'t manover when inertia above " + constants::maxManoveurSpeed, this);
    }
    this->direction = newDirection;
}

ShipControl *AbstractShip::getControl()
{
    return this->control;
}

void AbstractShip::addDamageObserver(Observer *observer)
{
    this->damageObservers->push_back(observer);
}

void AbstractShip::getDamaged(Damage *damage)
{
    for (size_t i = 0; i < this->damageObservers->size(); ++i) {
        this->damageObservers->at(i)->notify(this, damage);
    }

    this->armor->notify(this, damage);

    //Stage generators degradation
    int genIndex = rand() % this->stageGenerators->size();
    this->stageGenerators->at(genIndex)->getDamaged(damage);

    if(damage->getCurrentValue() > 0) {
        for (size_t i = 0; i < this->afterDamageObservers->size(); ++i) {
            this->afterDamageObservers->at(i)->notify(this, damage);
        }
    }
}

void AbstractShip::addAfterDamageObserver(Observer *observer)
{
    this->afterDamageObservers->push_back(observer);
}

void AbstractShip::destroy()
{
    std::cout << "Oh no, " << this->getName() << " is dead (not yet implemented)" << std::endl;
}
