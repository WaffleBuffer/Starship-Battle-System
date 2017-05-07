#include "abstractship.h"

#include <iostream>
#include <string>

AbstractShip::AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Thruster *forwardThruster, Thruster *backThruster,
             Thruster *leftTThruster, Thruster *frontTThruster, Thruster *rightTThruster, Thruster *backTThruster, Thruster *clockWiseThruster,
             Thruster *counterClockWiseThruster){

    this->name = name;
    this->description = description;

    this->hull = hull;

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
}

AbstractShip::~AbstractShip() {
    delete(this->hull);

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
    res += "thrusters :\n";
    res += this->getForwardThruster()->toString() + "\n";
    res += this->getBackThruster()->toString() + "\n";
    res += this->getLeftTThruster()->toString() + "\n";
    res += this->getFrontTThruster()->toString() + "\n";
    res += this->getRightTThruster()->toString() + "\n";
    res += this->getBackTThruster()->toString() + "\n";
    res += this->getClockWiseThruster()->toString() + "\n";
    res += this->getCounterClockWiseThruster()->toString() + "\n";

    res += "components : \n";

    for(size_t i = 0; i < this->components->size(); ++i) {
        res += this->components->at(i)->toString() + "\n";
    }

    return res;
}
