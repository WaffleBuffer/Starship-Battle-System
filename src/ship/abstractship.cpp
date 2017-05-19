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
#include "../utils/vectorialmovement.h"

#include <iostream>
#include <string>
#include <stdexcept>

AbstractShip::AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster,
                           NavThruster *backThruster, TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster,
                           TranslationThruster *backTThruster, RotationThruster *rotationThruster, VectorialMovement *movement)
    :IShip(movement), armor(armor), stageGenerators(new std::vector<StageGenerator*>()), damageObservers(new std::vector<Observer *>()),
      afterDamageObservers(new std::vector<Observer *>()){

    this->name = name;
    this->description = description;
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
    this->rotationThruster = rotationThruster;
    rotationThruster->setShip(this);

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
    delete(this->rotationThruster);
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
RotationThruster *AbstractShip::getRotationThruster() {
    return this->rotationThruster;
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

    res += Moveable::toString();

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
    res += "CR " + this->getRotationThruster()->toString() + "\n";

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
