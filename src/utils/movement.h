#ifndef MOVEMENT_H
#define MOVEMENT_H

/**
 * @file movement.h
 */

#include "moveable.h"
#include "../fileManager/saveHandler/xmlsavable.h"
#include <string>

/**
 * @brief The Movement class A type of movement on a plan. Abstract class
 */
class Movement: public XMLSavable
{
public:
    /**
     * @brief Movement The constructor
     * @param movingObject The moving object (just a link, nothing should be done on it).
     */
    Movement(Moveable *movingObject);
    virtual ~Movement() {}

    /**
     * @brief getMovingObject Get the moving object.
     * @return The moving object.
     */
    Moveable *getMovingObject();
    /**
     * @brief setMovingObject Set the moving object.
     * @param movingObject The moving object to set.
     */
    void setMovingObject(Moveable *movingObject);

    /**
     * @brief getDistance Get the distance to go.
     * @return The distance to go.
     */
    virtual double getDistance() = 0;

    /**
     * @brief setArrivingCoords Set new arriving coordinates.
     * @param xb The x position of the new point.
     * @param yb The y position of the new point.
     */
    virtual void setArrivingCoords(const double &xb, const double &yb) = 0;

private:
    /**
     * @brief movingObject The moving object. It shouldn't be modified.
     */
    Moveable *movingObject;
};

#endif // MOVEMENT_H
