#include "vectorialmovement.h"

#include <cmath>

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
    str += "(" + std::to_string(this->xPos) + ", " + std::to_string(this->yPos) +
           ") -> (" + std::to_string(this->getXB()) + ", " +
           std::to_string(this->getYB()) + ") : " + std::to_string(this->getDistance()) +
           " : " + std::to_string(this->getAngle()) + "° (" + (this->goingForward ? "forward)" : "backward") + "\n";

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
    pugi::xml_node thisRoot = root.append_child("vectorial_movement");

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
    node = thisRoot.append_child("angle");
    attr = node.append_attribute("angle");
    attr.set_value(this->angle);

    // GoingForward
    node = thisRoot.append_child("goingForward");
    attr = node.append_attribute("goingForward");
    attr.set_value(this->goingForward);
}
