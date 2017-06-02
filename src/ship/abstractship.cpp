#include "abstractship.h"
#include "component/energyComponents/abstractgenerator.h"
#include "component/sensor.h"
#include "hull.h"
#include "component/translationthruster.h"
#include "component/navthruster.h"
#include "component/rotationthruster.h"
#include "../utils/utils.cpp"
#include "../exception/shipexception.h"
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
      sternComponents(new std::vector<IComponent*>()), portComponents(new std::vector<IComponent*>()), sensors(new std::vector<Sensor*>())
      {

    this->name = name;
    this->description = description;
    this->control = new ShipControl(this);

    this->hull = hull;
    this->addAfterDamageObserver(this->hull);
    this->addComponentToPart(hull, constants::CORE);
    this->addComponentToPart(armor, constants::CORE);
    this->addSensors(baseSensor, constants::CORE);

    this->generators = new std::vector<AbstractGenerator*>();

    // Navigation thrusters
    this->forwardThruster = forwardThruster;
    forwardThruster->setFacingDirection(constants::BOW);
    this->addComponentToPart(forwardThruster, constants::CORE);
    this->backThruster = backThruster;
    backThruster->setFacingDirection(constants::STERN);
    this->addComponentToPart(backThruster, constants::CORE);

    // Maneuver thrusters
    // Translation thrusters
    this->leftTThruster = leftTThruster;
    leftTThruster->setFacingDirection(constants::PORT);
    this->addComponentToPart(leftTThruster, constants::CORE);
    this->frontTThruster = frontTThruster;
    frontTThruster->setFacingDirection(constants::BOW);
    this->addComponentToPart(frontTThruster, constants::CORE);
    this->rightTThruster = rightTThruster;
    rightTThruster->setFacingDirection(constants::STARBOARD);
    this->addComponentToPart(rightTThruster, constants::CORE);
    this->backTThruster = backTThruster;
    backTThruster->setFacingDirection(constants::STERN);
    this->addComponentToPart(backTThruster, constants::CORE);

    // Rotation thrusters
    this->rotationThruster = rotationThruster;
    this->addComponentToPart(rotationThruster, constants::CORE);

}

AbstractShip::AbstractShip()
    :generators(new std::vector<AbstractGenerator*>()), stageGenerators(new std::vector<StageGenerator*>()),
      damageObservers(new std::vector<Observer *>()), afterDamageObservers(new std::vector<Observer *>()),
      coreComponents(new std::vector<IComponent*>()), bowComponents(new std::vector<IComponent*>()), starboardComponents(new std::vector<IComponent*>()),
      sternComponents(new std::vector<IComponent*>()), portComponents(new std::vector<IComponent*>()), sensors(new std::vector<Sensor*>()){

}

AbstractShip::~AbstractShip() {

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

    delete(this->generators);
    delete(this->stageGenerators);
    delete(this->damageObservers);
    delete(this->afterDamageObservers);
    delete(this->sensors);

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
    component->setShip(this);
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
    if(this->stageGenerators->size() > 0) {
        int genIndex = rand() % this->stageGenerators->size();
        this->stageGenerators->at(genIndex)->getDamaged(damage);
    }

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

void AbstractShip::addSensors(Sensor *sensor, constants::shipParts shipPart)
{
    this->sensors->push_back(sensor);
    this->addComponentToPart(sensor, shipPart);
}

void AbstractShip::saveAbstractXML(pugi::xml_node &root, AbstractShip *shipToSave)
{
    root.append_attribute("name").set_value(shipToSave->getName().c_str());
    root.append_attribute("description").set_value(shipToSave->getDescription().c_str());
    shipToSave->getMovement()->saveXML(root);
    pugi::xml_node node;

    node = root.append_child("core");
    shipToSave->hull->saveXML(node);
    shipToSave->armor->saveXML(node);
    shipToSave->forwardThruster->saveXML(node);
    shipToSave->backThruster->saveXML(node);
    shipToSave->frontTThruster->saveXML(node);
    shipToSave->rightTThruster->saveXML(node);
    shipToSave->backTThruster->saveXML(node);
    shipToSave->leftTThruster->saveXML(node);
    shipToSave->rotationThruster->saveXML(node);
    pugi::xml_node underNode = node.append_child("base_generator");
    for(size_t i = 0; i < shipToSave->generators->size(); ++i) {
        if(shipToSave->generators->at(i)->getShipPart() == constants::CORE) {
            shipToSave->generators->at(i)->saveXML(underNode);
        }
    }
    underNode = node.append_child("base_sensor");
    for(size_t i = 0; i < shipToSave->sensors->size(); ++i) {
        if(shipToSave->sensors->at(i)->getShipPart() == constants::CORE) {
            shipToSave->sensors->at(i)->saveXML(underNode);
        }
    }

    node = root.append_child("bow");
    for(size_t i = 0; i < shipToSave->bowComponents->size(); ++i) {
        shipToSave->bowComponents->at(i)->saveXML(node);
    }

    node = root.append_child("starboard");
    for(size_t i = 0; i < shipToSave->starboardComponents->size(); ++i) {
        shipToSave->starboardComponents->at(i)->saveXML(node);
    }

    node = root.append_child("stern");
    for(size_t i = 0; i < shipToSave->sternComponents->size(); ++i) {
        shipToSave->sternComponents->at(i)->saveXML(node);
    }

    node = root.append_child("port");
    for(size_t i = 0; i < shipToSave->portComponents->size(); ++i) {
        shipToSave->portComponents->at(i)->saveXML(node);
    }
}

/**
 * @brief setNavThruster Set an existing NavThruster on an existing ship depending on the thruster facing direction (must be set).
 * @param ship The existing ship.
 * @param thruster The existing thruster with facingDirection set.
 */
void AbstractShip::setNavThruster(AbstractShip *ship, NavThruster *thruster) {

    switch (thruster->getFacingDirection()) {
    case constants::NORTH:
        ship->forwardThruster = thruster;
        break;
    case constants::SOUTH:
        ship->backThruster = thruster;
        break;
    default:
        throw std::invalid_argument( "Unknown or invalid direction for nav thruster to set to ship" );
        break;
    }
    ship->addComponentToPart(thruster, constants::CORE);
}

/**
 * @brief setTranslationThruster Set an existing TranslationThruster on an existing ship depending on the thruster facing direction (must be set).
 * @param ship The existing ship.
 * @param thruster The existing thruster with facingDirection set.
 */
void AbstractShip::setTranslationThruster(AbstractShip *ship, TranslationThruster *thruster) {

    switch (thruster->getFacingDirection()) {
    case constants::NORTH:
        ship->frontTThruster = thruster;
        break;
    case constants::EAST:
        ship->leftTThruster = thruster;
        break;
    case constants::SOUTH:
        ship->backTThruster = thruster;
        break;
    case constants::WEST:
        ship->rightTThruster = thruster;
        break;
    default:
        throw std::invalid_argument( "Unknown or invalid direction for translation thruster to set to ship" );
        break;
    }
    ship->addComponentToPart(thruster, constants::CORE);
}

void AbstractShip::loadAbstractFromXML(const pugi::xml_node &root, AbstractShip *shipToLoad)
{
    shipToLoad->name = root.attribute("name").as_string();
    shipToLoad->description = root.attribute("description").as_string();
    shipToLoad->setMovement(VectorialMovement::loadFromXML(shipToLoad, root.child(VectorialMovement::getRootName())));

    pugi::xml_node node = root.child("core");
    shipToLoad->hull = Hull::loadFromXML(shipToLoad, node.child(Hull::getRootName()));
    shipToLoad->addComponentToPart(shipToLoad->hull, constants::CORE);
    shipToLoad->armor = Armor::loadFromXML(shipToLoad, node.child(Armor::getRootName()));
    shipToLoad->addComponentToPart(shipToLoad->armor, constants::CORE);

    Sensor::loadFromXML(shipToLoad, node.child("base_sensor").first_child());
    for(pugi::xml_node currentNode = node.child(NavThruster::getRootName()); currentNode; currentNode = currentNode.next_sibling(NavThruster::getRootName())) {

        setNavThruster(shipToLoad, NavThruster::loadFromXML(shipToLoad, currentNode));
    }

    for(pugi::xml_node currentNode = node.child(TranslationThruster::getRootName()); currentNode; currentNode = currentNode.next_sibling(TranslationThruster::getRootName())) {
        setTranslationThruster(shipToLoad, TranslationThruster::loadFromXML(shipToLoad, currentNode));
    }
    shipToLoad->rotationThruster = RotationThruster::loadFromXML(shipToLoad, node.child(RotationThruster::getRootName()));
    shipToLoad->addComponentToPart(shipToLoad->rotationThruster, constants::CORE);

    AbstractGenerator::createGenFromXML(node.child("base_generator").first_child(), shipToLoad);
}
