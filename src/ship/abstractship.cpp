#include "abstractship.h"
#include "component/energyComponents/abstractgenerator.h"
#include "component/sensor.h"
#include "hull.h"
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

AbstractShip::AbstractShip(const std::string & name, const std::string & description, Hull *hull, Armor *armor, Sensor *baseSensor, NavThruster *forwardThruster,
                           NavThruster *backThruster, TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster,
                           TranslationThruster *backTThruster, RotationThruster *rotationThruster, VectorialMovement *movement)
    :IShip(movement), armor(armor), stageGenerators(new std::vector<StageGenerator*>()), damageObservers(new std::vector<Observer *>()),
      afterDamageObservers(new std::vector<Observer *>()),
      coreComponents(new std::vector<IComponent*>()), bowComponents(new std::vector<IComponent*>()), starboardComponents(new std::vector<IComponent*>()),
      sternComponents(new std::vector<IComponent*>()), portComponents(new std::vector<IComponent*>())
      {

    this->name = name;
    this->description = description;
    this->control = new ShipControl(this);

    this->hull = hull;
    this->addAfterDamageObserver(this->hull);
    this->addComponentToPart(hull, constants::CORE);
    this->sensor = baseSensor;
    this->addComponentToPart(armor, constants::CORE);
    baseSensor->setShip(this);
    this->addComponentToPart(sensor, constants::CORE);

    // Navigation thrusters
    this->forwardThruster = forwardThruster;
    forwardThruster->setShip(this);
    forwardThruster->setFacingDirection(constants::BOW);
    this->addComponentToPart(forwardThruster, constants::CORE);
    this->backThruster = backThruster;
    backThruster->setShip(this);
    backThruster->setFacingDirection(constants::STERN);
    this->addComponentToPart(backThruster, constants::CORE);

    // Maneuver thrusters
    // Translation thrusters
    this->leftTThruster = leftTThruster;
    leftTThruster->setShip(this);
    leftTThruster->setFacingDirection(constants::PORT);
    this->addComponentToPart(leftTThruster, constants::CORE);
    this->frontTThruster = frontTThruster;
    frontTThruster->setShip(this);
    frontTThruster->setFacingDirection(constants::BOW);
    this->addComponentToPart(frontTThruster, constants::CORE);
    this->rightTThruster = rightTThruster;
    rightTThruster->setShip(this);
    rightTThruster->setFacingDirection(constants::STARBOARD);
    this->addComponentToPart(rightTThruster, constants::CORE);
    this->backTThruster = backTThruster;
    backTThruster->setShip(this);
    backTThruster->setFacingDirection(constants::STERN);
    this->addComponentToPart(backTThruster, constants::CORE);

    // Rotation thrusters
    this->rotationThruster = rotationThruster;
    rotationThruster->setShip(this);
    this->addComponentToPart(rotationThruster, constants::CORE);

    this->generators = new std::vector<AbstractGenerator*>();
}

AbstractShip::~AbstractShip() {
    /*delete(this->hull);
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

    for(size_t i = 0; i < this->generators->size(); ++i) {
        delete(this->generators->at(i));
    }*/
    delete(this->generators);
    delete(this->stageGenerators);

    for(size_t i = 0; i < this->coreComponents->size(); ++i) {
        delete(this->coreComponents->at(i));
    }
    delete(this->coreComponents);

    for(size_t i = 0; i < this->bowComponents->size(); ++i) {
        delete(this->bowComponents->at(i));
    }
    delete(this->bowComponents);

    for(size_t i = 0; i < this->starboardComponents->size(); ++i) {
        delete(this->starboardComponents->at(i));
    }
    delete(this->starboardComponents);

    for(size_t i = 0; i < this->sternComponents->size(); ++i) {
        delete(this->sternComponents->at(i));
    }
    delete(this->sternComponents);

    for(size_t i = 0; i < this->portComponents->size(); ++i) {
        delete(this->portComponents->at(i));
    }
    delete(this->portComponents);

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

void AbstractShip::addComponentToPart(IComponent *component, constants::shipParts shipPart) {
    switch (shipPart) {
    case constants::CORE:
        this->coreComponents->push_back(component);
        component->setPart(constants::CORE);
        break;
    case constants::BOW_PART:
        this->bowComponents->push_back(component);
        component->setPart(constants::BOW_PART);
        break;
    case constants::STARBOARD_PART:
        this->starboardComponents->push_back(component);
        component->setPart(constants::STARBOARD_PART);
        break;
    case constants::STERN_PART:
        this->sternComponents->push_back(component);
        component->setPart(constants::STERN_PART);
        break;
    case constants::PORT_PART:
        this->portComponents->push_back(component);
        component->setPart(constants::PORT_PART);
        break;
    default:
        break;
    }
}

std::string AbstractShip::toString()
{
    std::string res = "";
    res += this->getName() + "\n";
    res += this->getDescription() + "\n";

    res += Moveable::toString();

    /*res += "armor : " + this->armor->toString() + "\n";
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
    }*/

    res += "=========CORE===========\n";

    for (size_t i = 0; i < this->coreComponents->size(); ++i) {
        res += this->coreComponents->at(i)->toString() + "\n";
    }

    res += "========================\n";

    res += "=========BOW===========\n";

    for (size_t i = 0; i < this->bowComponents->size(); ++i) {
        res += this->bowComponents->at(i)->toString() + "\n";
    }

    res += "========================\n";

    res += "=========STARBOARD===========\n";

    for (size_t i = 0; i < this->starboardComponents->size(); ++i) {
        res += this->starboardComponents->at(i)->toString() + "\n";
    }

    res += "========================\n";

    res += "=========STERN===========\n";

    for (size_t i = 0; i < this->sternComponents->size(); ++i) {
        res += this->sternComponents->at(i)->toString() + "\n";
    }

    res += "========================\n";

    res += "=========PORT===========\n";

    for (size_t i = 0; i < this->portComponents->size(); ++i) {
        res += this->portComponents->at(i)->toString() + "\n";
    }

    res += "========================\n";

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

void AbstractShip::addGenerator(AbstractGenerator *generator, constants::shipParts shipPart)
{
    this->generators->push_back(generator);
    generator->setShip(this);
    StageGenerator *stageGenerator = dynamic_cast<StageGenerator*>(generator);
    if(stageGenerator != NULL) {
        this->stageGenerators->push_back(stageGenerator);
    }

    this->addComponentToPart(generator, shipPart);
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
    // First notify everything that can reduce the damage
    for (size_t i = 0; i < this->damageObservers->size(); ++i) {
        this->damageObservers->at(i)->notify(this, damage);
    }

    if(damage->getCurrentValue() <= 0) {
        return;
    }

    // Then the armor
    this->armor->notify(this, damage);

    if(damage->getCurrentValue() <= 0) {
        return;
    }

    damage->rollDamage();

    // Stage generators degradation
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
