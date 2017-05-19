#ifndef VECTORIALMOVEMENT_H
#define VECTORIALMOVEMENT_H

#include "movement.h"

class VectorialMovement: public Movement
{
public:
    VectorialMovement(Moveable *movingObject, const int &baseAngle);

    double getXPos() const;
    double getYPos() const;
    double getXOffset() const;
    double getYOffset() const;

    void setXPos(double value);
    void setYPos(double value);
    void setXOffset(double value);
    void setYOffset(double value);

    double getDistance();

    void setArrivingCoords(const double &xb, const double &yb);
    double getXB();
    double getYB();

    double getAngle() const;
    void setAngle(double value);

    std::string toString();

    bool getGoingUp() const;
    void setGoingUp(bool value);

private:

    double xPos;
    double yPos;

    double xOffset;
    double yOffset;

    double angle;

    bool goingUp;
};

#endif // VECTORIALMOVEMENT_H
