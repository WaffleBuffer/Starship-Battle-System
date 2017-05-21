#ifndef MOVEABLE_H
#define MOVEABLE_H

/**
 * @file movable.h
 **/

#include "constants.cpp"

#include <string>

class VectorialMovement;

/**
 * @brief The Moveable class. An object that has coordonates and that can move. A Movable object is only a vectorial movable.
 *        We should also add a nextTurn movement to separate current maneuvers and navigation.
 */
class Moveable
{
public:
    /**
     * @brief Moveable The constructor.
     * @param movement The type of movement that should be applied.
     */
    Moveable(VectorialMovement *movement);
    virtual ~Moveable();

    /**
     * @brief addInertia Add inertia to the object. Only forward and backward alowed.
     * @param direction The direction of the inertia. Only NORTH or SOUTH (forward or backward).
     * @param distance The value of the inertia to add.
     */
    virtual void addInertia(constants::Direction direction, double distance);
    /**
     * @brief translate Make a translation move without inertia effect.
     * @param direction The direction of the translation.
     * @param distance The distance of the translation.
     */
    virtual void translate(constants::Direction direction, double distance);
    /**
     * @brief move Go to the current destination. An idea is to add an int parameter to choose if you want to go all the way,
     *             or if you want to partially move (usefull for maneuvers). This parameter should be 0 < distance < movement->getDistance()
     */
    virtual void move();
    /**
     * @brief rotate
     * @param angleOffset
     */
    virtual void rotate(const double &angleOffset);

    /**
     * @brief getMovement Get the current movement
     * @return The current movement
     */
    VectorialMovement *getMovement() const;

    /**
     * @brief toString Get the string representation of coordonates and inertia.
     * @return The string representation of coordonates and inertia.
     */
    std::string toString();

private:
    /**
     * @brief movement The current vectorial movement.
     */
    VectorialMovement *movement;

};

#endif // MOVEABLE_H
