#include "abstractship.h"
#include "component/abstractgenerator.h"
#include "component/sensor.h"

#include <iostream>
#include <string>

AbstractShip::AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Sensor *sensor, Thruster *forwardThruster, Thruster *backThruster,
             Thruster *leftTThruster, Thruster *frontTThruster, Thruster *rightTThruster, Thruster *backTThruster, Thruster *clockWiseThruster,
             Thruster *counterClockWiseThruster){

    this->name = name;
    this->description = description;
    this->currentEnergy = 0;
    this->inertia = 0;

    this->hull = hull;
    this->sensor = sensor;

    // Navigation thrusters
    this->forwardThruster = forwardThruster;
    this->backThruster = backThruster;

    // Maneuver thrusters
    // Translation thrusters
    this->leftTThruster = leftTThruster;
    this->frontTThruster = frontTThruster;
    this->rightTThruster = rightTThruster;
    this->backTThruster = backTThruster;

    // Rotation thrusters
    this->clockWiseThruster = clockWiseThruster;
    this->counterClockWiseThruster = counterClockWiseThruster;

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
Thruster *AbstractShip::getForwardThruster() {
    return this->forwardThruster;
}

Thruster *AbstractShip::getBackThruster() {
    return this->backThruster;
}

// Maneuver thrusters
// Translation thrusters
Thruster *AbstractShip::getLeftTThruster() {
    return this->leftTThruster;
}

Thruster *AbstractShip::getFrontTThruster() {
    return this->frontTThruster;
}

Thruster *AbstractShip::getRightTThruster() {
    return this->rightTThruster;
}

Thruster *AbstractShip::getBackTThruster() {
    return this->backTThruster;
}

// Rotation thrusters
Thruster *AbstractShip::getClockWiseThruster() {
    return this->clockWiseThruster;
}

Thruster *AbstractShip::getCounterClockWiseThruster() {
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

    res += "hull : " + this->hull->toString() + "\n";

    res += "sensor : " + this->sensor->toString() + "\n";

    res += "energy : ";
    res += std::to_string(this->currentEnergy) + "\n";

    res += "thrusters :\n";
    res += "F " + this->getForwardThruster()->toString() + "\n";
    res += "B " + this->getBackThruster()->toString() + "\n";
    res += "LT " + this->getLeftTThruster()->toString() + "\n";
    res += "FT " + this->getFrontTThruster()->toString() + "\n";
    res += "RT " + this->getRightTThruster()->toString() + "\n";
    res += "BT " + this->getBackTThruster()->toString() + "\n";
    res += "CT " + this->getClockWiseThruster()->toString() + "\n";
    res += "CCT " + this->getCounterClockWiseThruster()->toString() + "\n";

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

    this->currentEnergy = energy;
    return this->currentEnergy;
}

std::vector<AbstractGenerator *> *AbstractShip::getGenerators()
{
    return this->generators;
}

void AbstractShip::addGenerator(AbstractGenerator *generator)
{
    this->generators->push_back(generator);
}

int AbstractShip::getCurrentEnergy()
{
    return this->currentEnergy;
}

Sensor *AbstractShip::getSensor()
{
    return this->sensor;
}

int AbstractShip::getInertia()
{
    return this->inertia;
}
