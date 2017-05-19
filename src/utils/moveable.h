#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "constants.cpp"

#include <string>

class VectorialMovement;

class Moveable
{
public:
    Moveable(VectorialMovement *movement);
    virtual ~Moveable();

    virtual void addInertia(constants::Direction direction, double distance);
    virtual void translate(constants::Direction direction, double distance);
    virtual void move();
    virtual void rotate(const double &angleOffset);

    VectorialMovement *getMovement() const;

    std::string toString();

private:
    VectorialMovement *movement;

};

#endif // MOVEABLE_H
