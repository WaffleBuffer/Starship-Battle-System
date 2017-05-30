#ifndef ISHIP_H
#define ISHIP_H

/**
 * @file iship.h
 */

#include "../utils/constants.cpp"
#include "../utils/observable.h"
#include "damageable.h"
#include "../utils/moveable.h"

#include <string>
#include <vector>

class IComponent;
class NavThruster;
class TranslationThruster;
class RotationThruster;
class Hull;
class AbstractGenerator;
class Sensor;
class ShipControl;
class Observer;
class Damage;
class VectorialMovement;

/**
 * @brief The IShip class. The interface. Not very usefull at the moment but who knows.
 */
class IShip: public Observable, public Damageable, public Moveable
{
public:
    /**
     * @brief IShip The constructor.
     * @param movement The movement handler.
     */
    IShip(VectorialMovement *movement);
    virtual ~IShip() {}

    /**
     * @brief getName Get the ship's name.
     * @return The ship's name.
     */
    virtual std::string getName() = 0;
    /**
     * @brief getDescription Get the ship's description.
     * @return Get the ship's description.
     */
    virtual std::string getDescription() = 0;

    // Navigation thrusters
    /**
     * @brief getForwardThruster Get FT.
     * @return FT.
     */
    virtual NavThruster *getForwardThruster() = 0;
    /**
     * @brief getBackThruster Get BT.
     * @return BT.
     */
    virtual NavThruster *getBackThruster() = 0;

    // Maneuver thrusters
    // Translation thrusters
    /**
     * @brief getLeftTThruster Get LTT.
     * @return LTT.
     */
    virtual TranslationThruster *getLeftTThruster() = 0;
    /**
     * @brief getFrontTThruster Get FTT.
     * @return FTT.
     */
    virtual TranslationThruster *getFrontTThruster() = 0;
    /**
     * @brief getRightTThruster Get RTT.
     * @return RTT.
     */
    virtual TranslationThruster *getRightTThruster() = 0;
    /**
     * @brief getBackTThruster Get BTT.
     * @return BTT.
     */
    virtual TranslationThruster *getBackTThruster() = 0;

    // Rotation thrusters
    /**
     * @brief getRotationThruster Get RT.
     * @return RT.
     */
    virtual RotationThruster *getRotationThruster() = 0;

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    virtual std::string toString() = 0;

    /**
     * @brief generateEnergy Generate energy for a turn and stock it in the Ship's control.
     * @return The generated energy.
     */
    virtual int generateEnergy() = 0;

    /**
     * @brief getGenerators Get all energy generators.
     * @return The generators.
     */
    virtual std::vector<AbstractGenerator*> *getGenerators() = 0;
    /**
     * @brief addGenerator Add a generator.
     * @param generator The generator to add.
     */
    virtual void addGenerator(AbstractGenerator *generator, constants::shipParts shipPart) = 0;

    /**
     * @brief getControl Get the ship's control.
     * @return The ship's control.
     */
    virtual ShipControl *getControl() = 0;

    /**
     * @brief addDamageObserver Add a damage observer.
     * @param observer The observer.
     */
    virtual void addDamageObserver(Observer *observer) = 0;

    /**
     * @brief addAfterDamageObserver Add an observer to trigger after some damage points have been taken.
     * @param observer The observer.
     */
    virtual void addAfterDamageObserver(Observer *observer) = 0;
    /**
     * @brief destroy Destroy this ship (not delete).
     */
    virtual void destroy() = 0;

    /**
     * @brief addSensors Add some sensors.
     * @param sensor The sensor to add.
     * @param shipPart The ship part where you want to add the sensors.
     */
    virtual void addSensors(Sensor *sensor, constants::shipParts shipPart) = 0;
};

#endif // ISHIP_H
