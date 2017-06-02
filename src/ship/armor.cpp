#include "armor.h"

#include "../ship/damage.h"
#include "iship.h"
#include "../exception/xmlexception.h"
#include <string.h>

const char* Armor::rootName = "armor";

Armor::Armor(const int &bowMax, const int &starMax, const int &sternMax, const int &portMax)
    :AbstractComponent("", "", nullptr), bowMax(bowMax), bowCurrentValue(bowMax), starBoardMax(starMax), starBoardCurrentValue(starMax),
     sternMax(sternMax), sternCurrentValue(sternMax), portMax(portMax), portCurrentValue(portMax){

}

void Armor::notify(Observable *origin, MyObject *arg)
{
    IShip *ship = dynamic_cast<IShip*> (origin);
    if(ship == NULL) {
        return;
    }
    Damage *damageTaken = dynamic_cast<Damage*>(arg);
    if(damageTaken == NULL) {
        return;
    }

    switch (damageTaken->getFaceTargeted()) {
    case constants::BOW:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->bowCurrentValue);
        // In new rules there is no more armor degradation
        /*if(this->bowCurrentValue > 0)
            this->bowCurrentValue--;*/
        break;
    case constants::STARBOARD:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->starBoardCurrentValue);
        /*if(this->starBoardCurrentValue > 0)
            this->starBoardCurrentValue--;*/
        break;
    case constants::STERN:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->sternCurrentValue);
        /*if(this->sternCurrentValue > 0)
            this->sternCurrentValue--;*/
        break;
    case constants::PORT:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->portCurrentValue);
        /*if(this->portCurrentValue > 0)
            this->portCurrentValue--;*/
        break;
    }

}

std::string Armor::toString()
{
    std::string res = "";
    res += "{" + std::to_string(this->bowCurrentValue) + ", " + std::to_string(this->starBoardCurrentValue) +
           ", " + std::to_string(this->sternCurrentValue) + ", " + std::to_string(this->portCurrentValue) + "}";
    return res;
}

void Armor::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(Armor::getRootName());
    AbstractComponent::saveAbstractXML(thisRoot, this);

    pugi::xml_node node = thisRoot.append_child("bow");
    node.append_attribute("max").set_value(this->bowMax);
    node.append_attribute("current").set_value(this->bowCurrentValue);
    node = thisRoot.append_child("starboard");
    node.append_attribute("max").set_value(this->starBoardMax);
    node.append_attribute("current").set_value(this->starBoardCurrentValue);
    node = thisRoot.append_child("stern");
    node.append_attribute("max").set_value(this->sternMax);
    node.append_attribute("current").set_value(this->sternCurrentValue);
    node = thisRoot.append_child("port");
    node.append_attribute("max").set_value(this->portMax);
    node.append_attribute("current").set_value(this->portCurrentValue);
}

Armor *Armor::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), Armor::getRootName()) != 0)
        throw XMLException("Wrong node to load for Armor : " + std::string(root.name()));

    Armor *armor = new Armor(0,0,0,0);
    AbstractComponent::loadAbstractFromXML(ship, root, armor);
    pugi::xml_node node;

    node = root.child("bow");
    armor->bowMax = node.attribute("max").as_int();
    armor->bowCurrentValue = node.attribute("current").as_int();
    node = root.child("starboard");
    armor->starBoardMax = node.attribute("max").as_int();
    armor->starBoardCurrentValue = node.attribute("current").as_int();
    node = root.child("stern");
    armor->sternMax = node.attribute("max").as_int();
    armor->sternCurrentValue = node.attribute("current").as_int();
    node = root.child("port");
    armor->portMax = node.attribute("max").as_int();
    armor->portCurrentValue = node.attribute("current").as_int();

    return armor;
}

const char *Armor::getRootName()
{
    return rootName;
}
