#ifndef VECTORIALMOVEMENT_H
#define VECTORIALMOVEMENT_H

/**
 * @file vectorialmovement.h
 */

#include "movement.h"

/**
 * @brief The VectorialMovement class. A vector on a cartesian plan.
 */
class VectorialMovement: public Movement
{
public:
    /**
     * @brief VectorialMovement The constructor.
     * @param movingObject The object linked to this movement.
     * @param baseAngle The starting angle (0 is the X axis).
     */
    VectorialMovement(Moveable *movingObject, const int &baseAngle);

    /**
     * @brief getXPos Get origin X position.
     * @return Origin X position.
     */
    double getXPos() const;
    /**
     * @brief getYPos Get origin Y position.
     * @return Origin Y position.
     */
    double getYPos() const;
    /**
     * @brief getXOffset Get X difference between origin and arrival.
     * @return X difference between origin and arrival.
     */
    double getXOffset() const;
    /**
     * @brief getYOffset Get Y difference between origin and arrival.
     * @return Y difference between origin and arrival.
     */
    double getYOffset() const;

    /**
     * @brief setXPos Set X origin.
     * @param value The X origin
     */
    void setXPos(double value);
    /**
     * @brief setYPos Set Y origin.
     * @param value Y origin.
     */
    void setYPos(double value);
    /**
     * @brief setXOffset Set difference between X arriving point and X origin.
     * @param value X offset.
     */
    void setXOffset(double value);
    /**
     * @brief setYOffset Set the difference between arrivint point Y and origin Y.
     * @param value Y offset.
     */
    void setYOffset(double value);

    /**
     * @brief getDistance Get the distance between origin point and arriving point.
     * @return
     */
    double getDistance() override;

    /**
     * @brief setArrivingCoords Set the arriving point by coordonates.
     * @param xb Arriving point X.
     * @param yb Arriving point Y.
     */
    void setArrivingCoords(const double &xb, const double &yb) override;
    /**
     * @brief getXB Get arriving point X.
     * @return Arriving point X
     */
    double getXB();
    /**
     * @brief getYB Get arriving point Y.
     * @return Arriving point Y.
     */
    double getYB();

    /**
     * @brief getAngle Get the angle (0 is the X axis).
     * @return The angle
     */
    double getAngle() const;
    /**
     * @brief setAngle Set the angle (0 is the X axis).
     * @param value The angle.
     */
    void setAngle(double value);

    /**
     * @brief toString Get a string representation of the vector.
     * @return The string representation.
     */
    std::string toString();

    /**
     * @brief getGoingForward Get if the moving object is going forward.
     *                        TODO: move this in IShip.
     * @return Is the ship going forward.
     */
    bool getGoingForward() const;
    /**
     * @brief setgoingForward Set if the moving object is going forward.
     *                        TODO: move this in IShip.
     * @param value Is the ship going forward.
     */
    void setgoingForward(bool value);


private:

    /**
     * @brief xPos Origin X.
     */
    double xPos;
    /**
     * @brief yPos Origin Y.
     */
    double yPos;

    /**
     * @brief xOffset Difference between arriving point X and origin X.
     */
    double xOffset;
    /**
     * @brief yOffset Difference between arriving point Y and origin Y.
     */
    double yOffset;

    /**
     * @brief angle Angle (0 is X axis).
     */
    double angle;

    /**
     * @brief goingForward Is the ship going forward. TODO: move this in IShip.
     */
    bool goingForward;
};

#endif // VECTORIALMOVEMENT_H
