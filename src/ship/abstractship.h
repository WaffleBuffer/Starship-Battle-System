#ifndef ABSTRACTSHIP_H
#define ABSTRACTSHIP_H

#include "iship.h"

class Sensor;
class Armor;
class StageGenerator;

class AbstractShip : public IShip
{
public:
    AbstractShip(const std::string & name, const std::string & description, AbstractHull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
                 TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
                 RotationThruster *rotationThruster,  VectorialMovement *movement);
    virtual ~AbstractShip();

    std::string getName() override;
    std::string getDescription() override;

    // Navigation thrusters
    NavThruster *getForwardThruster() override;
    NavThruster *getBackThruster() override;

    // Maneuver thrusters
    // Translation thrusters
    TranslationThruster *getLeftTThruster() override;
    TranslationThruster *getFrontTThruster() override;
    TranslationThruster *getRightTThruster() override;
    TranslationThruster *getBackTThruster() override;

    // Rotation thrusters
    RotationThruster *getRotationThruster() override;

    // Components
    std::vector<IComponent*> *getComponents() override;

    std::string toString() override;

    int generateEnergy() override;
    std::vector<AbstractGenerator*> *getGenerators() override;
    void addGenerator(AbstractGenerator *generator);

    Sensor *getSensor() override;

    ShipControl *getControl() override;

    void addDamageObserver(Observer *observer) override;
    void getDamaged(Damage *damage) override;
    void addAfterDamageObserver(Observer *observer) override;

    void destroy() override;

private:
    std::string name;
    std::string description;

    AbstractHull *hull;
    Armor *armor;

    // Navigation thrusters
    NavThruster *forwardThruster;
    NavThruster *backThruster;

    // Maneuver thrusters
    // Translation thrusters
    TranslationThruster *leftTThruster;
    TranslationThruster *frontTThruster;
    TranslationThruster *rightTThruster;
    TranslationThruster *backTThruster;

    // Rotation thrusters
    RotationThruster *rotationThruster;
    RotationThruster *counterClockWiseThruster;

    // Components
    std::vector<IComponent*> *components;

    std::vector<AbstractGenerator*> *generators;
    std::vector<StageGenerator*> *stageGenerators;

    Sensor *sensor;

    ShipControl *control;

    std::vector<Observer *> *damageObservers;
    std::vector<Observer *> *afterDamageObservers;
};

#endif // ABSTRACTSHIP_H
