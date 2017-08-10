#include "vectorialmovement.h"

#include "../exception/xmlexception.h"
#include "../thirdParty/pugixml-1.8/src/pugixml.hpp"
#include <cmath>
#include <string.h>
#include <iomanip>
#include <sstream>

const char* VectorialMovement::rootName = "vectorial_movement";

VectorialMovement::VectorialMovement(Moveable *movingObject, const int &baseAngle)
    :Movement(movingObject), xPos(0), yPos(0), xOffset(0), yOffset(0), angle(baseAngle),
    goingForward(false){

}

double VectorialMovement::getXPos() const
{
    return xPos;
}

double VectorialMovement::getYPos() const
{
    return yPos;
}

double VectorialMovement::getXOffset() const
{
    return xOffset;
}

double VectorialMovement::getYOffset() const
{
    return yOffset;
}

void VectorialMovement::setXPos(double value)
{
    xPos = value;
}

void VectorialMovement::setYPos(double value)
{
    yPos = value;
}

void VectorialMovement::setXOffset(double value)
{
    xOffset = value;
}

void VectorialMovement::setYOffset(double value)
{
    yOffset = value;
}

double VectorialMovement::getDistance()
{
    double x = (this->getXPos() + this->getXOffset()) - this->getXPos();
    double y = (this->getYPos() + this->getYOffset()) - this->getYPos();

    double res = sqrt(pow(x, 2) + pow(y, 2));

    return res;
}

void VectorialMovement::setArrivingCoords(const double &xb, const double &yb)
{
    this->xOffset = xb - this->getXPos();
    this->yOffset = yb - this->getYPos();
}

double VectorialMovement::getXB()
{
    return this->xPos + this->xOffset;
}

double VectorialMovement::getYB()
{
    return this->yPos + this->yOffset;
}

double VectorialMovement::getAngle() const
{
    return angle;
}

void VectorialMovement::setAngle(double value)
{
    angle = value;
}

std::string VectorialMovement::toString()
{
    std::string str = "";
    std::stringstream stream;

    stream << std::fixed << std::setprecision(2) << this->xPos;
    str += "(" + stream.str() + ", ";

    stream.str(std::string());
    stream << std::fixed << std::setprecision(2) << this->yPos;
    str += stream.str() + ") -> (";

    stream.str(std::string());
    stream << std::fixed << std::setprecision(2) << this->getXB();
    str += stream.str() + ", ";

    stream.str(std::string());
    stream << std::fixed << std::setprecision(2) << this->getYB();
    str += stream.str() + ") : distance ";

    stream.str(std::string());
    stream << std::fixed << std::setprecision(2) << this->getDistance();
    str += stream.str() + " : angle ";

    stream.str(std::string());
    stream << std::fixed << std::setprecision(2) << this->getAngle();
    str += stream.str() + "° (" + (this->goingForward ? "forward)" : "backward") + "\n";

    return str;
}

bool VectorialMovement::getGoingForward() const
{
    return goingForward;
}

void VectorialMovement::setgoingForward(bool value)
{
    goingForward = value;
}

void VectorialMovement::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(VectorialMovement::getRootName());

    // Pos
    pugi::xml_node node = thisRoot.append_child("pos");

    pugi::xml_attribute attr = node.append_attribute("xPos");
    attr.set_value(this->xPos);
    attr = node.append_attribute("yPos");
    attr.set_value(this->yPos);

    // Offset
    node = thisRoot.append_child("offset");
    attr = node.append_attribute("xOffset");
    attr.set_value(this->xOffset);
    attr = node.append_attribute("yOffset");
    attr.set_value(this->yOffset);

    // Angle
    attr = thisRoot.append_attribute("angle");
    attr.set_value(this->angle);

    // GoingForward
    attr = thisRoot.append_attribute("goingForward");
    attr.set_value(this->goingForward);
}

VectorialMovement *VectorialMovement::loadFromXML(Moveable *movingObject, const pugi::xml_node &root)
{
    if(strcmp(root.name(), VectorialMovement::getRootName()) != 0)
        throw XMLException("Wrong node to load for Vectorial Movement : " + std::string(root.name()));

    VectorialMovement *movement = new VectorialMovement(movingObject, root.attribute("angle").as_double());

    pugi::xml_node node = root.child("pos");
    movement->setXPos(node.attribute("xPos").as_double());
    movement->setYPos(node.attribute("yPos").as_double());

    node = root.child("offset");
    movement->setXOffset(node.attribute("xOffset").as_double());
    movement->setYOffset(node.attribute("yOffset").as_double());

    movement->setgoingForward(root.attribute("goingForward").as_bool());

    return movement;
}

const char*VectorialMovement::getRootName()
{
    return VectorialMovement::rootName;
}
