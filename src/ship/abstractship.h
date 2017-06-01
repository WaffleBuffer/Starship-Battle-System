#ifndef ABSTRACTSHIP_H
#define ABSTRACTSHIP_H

/**
 * @abstractship.h
 */

#include "iship.h"

class Sensor;
class Armor;
class StageGenerator;

/**
 * @brief The AbstractShip class. A basic ship.
 */
class AbstractShip : public IShip
{
public:
    /**
     * @brief AbstractShip The constructor.
     * @param name The ship's name.
     * @param description The ship's description.
     * @param hull The ship's hull.
     * @param armor The ship's armor.
     * @param sensor The ship's basic sensors.
     * @param forwardThruster FT.
     * @param backThruster BT.
     * @param leftTThruster LTT.
     * @param frontTThruster FTT.
     * @param rightTThruster RTT.
     * @param backTThruster BTT.
     * @param rotationThruster RT.
     * @param movement The movement handler.
     */
    AbstractShip(const std::string & name, const std::string & description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
                 TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
                 RotationThruster *rotationThruster,  VectorialMovement *movement);
    virtual ~AbstractShip();

    /**
     * @brief getName Get the ship's name.
     * @return The ship's name.
     */
    std::string getName() override;
    /**
     * @brief getDescription Get the ship's description.
     * @return Get the ship's description.
     */
    std::string getDescription() override;

    // Navigation thrusters
    /**
     * @brief getForwardThruster Get FT.
     * @return FT.
     */
    NavThruster *getForwardThruster() override;
    /**
     * @brief getBackThruster Get BT.
     * @return BT.
     */
    NavThruster *getBackThruster() override;

    // Maneuver thrusters
    // Translation thrusters
    /**
     * @brief getLeftTThruster Get LTT.
     * @return LTT.
     */
    TranslationThruster *getLeftTThruster() override;
    /**
     * @brief getFrontTThruster Get FTT.
     * @return FTT.
     */
    TranslationThruster *getFrontTThruster() override;
    /**
     * @brief getRightTThruster Get RTT.
     * @return RTT.
     */
    TranslationThruster *getRightTThruster() override;
    /**
     * @brief getBackTThruster Get BTT.
     * @return BTT.
     */
    TranslationThruster *getBackTThruster() override;

    // Rotation thrusters
    /**
     * @brief getRotationThruster Get RT.
     * @return RT.
     */
    RotationThruster *getRotationThruster() override;

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;

    /**
     * @brief generateEnergy Generate energy for a turn and stock it in the Ship's control.
     * @return The generated energy.
     */
    int generateEnergy() override;
    /**
     * @brief getGenerators Get all energy generators.
     * @return The generators.
     */
    std::vector<AbstractGenerator*> *getGenerators() override;
    /**
     * @brief addGenerator Add a generator.
     * @param generator The generator to add.
     */
    void addGenerator(AbstractGenerator *generator, constants::shipParts shipPart);

    /**
     * @brief getControl Get the ship's control.
     * @return The ship's control.
     */
    ShipControl *getControl() override;

    /**
     * @brief addDamageObserver Add a damage observer.
     * @param observer The observer.
     */
    void addDamageObserver(Observer *observer) override;
    /**
     * @brief getDamaged Take some damage.
     * @param damage The damage to take.
     */
    void getDamaged(Damage *damage) override;
    /**
     * @brief addAfterDamageObserver Add an observer to trigger after some damage points have been taken.
     * @param observer The observer.
     */
    void addAfterDamageObserver(Observer *observer) override;

    /**
     * @brief destroy Destroy this ship (not delete).
     */
    void destroy() override;

    /**
     * @brief addSensors Add some sensors.
     * @param sensor The sensor to add.
     * @param shipPart The ship part where you want to add the sensors.
     */
    void addSensors(Sensor *sensor, constants::shipParts shipPart) override;

    /**
     * @brief saveXML Save the AbstractShip infos of an AbstractShip.
     * @param root The root xml tag that should contain this object.
     * @param componentToLoad The AbstractShip from which you want to save infos.
     */
    static void saveAbstractXML(pugi::xml_node &root, AbstractShip *componentToLoad);

    /**
     * @brief loadFromXML Load AbstractShip infos into an AbstractShip.
     * @param root The xml node that should contain the AbstractShip informations.
     * @param componentToLoad The AbstractShip into which you want to save infos.
     */
    static void loadAbstractFromXML(const pugi::xml_node &root, AbstractShip *componentToLoad);


private:
    /**
     * @brief name The ship's name.
     */
    std::string name;
    /**
     * @brief description The ship's description.
     */
    std::string description;

    /**
     * @brief hull The ship's hull.
     */
    Hull *hull;
    /**
     * @brief armor The ship's armor.
     */
    Armor *armor;

    // Navigation thrusters
    /**
     * @brief forwardThruster FT.
     */
    NavThruster *forwardThruster;
    /**
     * @brief backThruster BT.
     */
    NavThruster *backThruster;

    // Maneuver thrusters
    // Translation thrusters
    /**
     * @brief leftTThruster LTT.
     */
    TranslationThruster *leftTThruster;
    /**
     * @brief frontTThruster FTT.
     */
    TranslationThruster *frontTThruster;
    /**
     * @brief rightTThruster RTT.
     */
    TranslationThruster *rightTThruster;
    /**
     * @brief backTThrusterBTT
     */
    TranslationThruster *backTThruster;

    // Rotation thrusters
    /**
     * @brief rotationThruster RT.
     */
    RotationThruster *rotationThruster;

    /**
     * @brief generators The ship's generators.
     */
    std::vector<AbstractGenerator*> *generators;
    /**
     * @brief stageGenerators The ship's stage generators (included in generators).
     *                        Used to deteriorate only one stage generator (randomly) per hit.
     */
    std::vector<StageGenerator*> *stageGenerators;

    /**
     * @brief control The ship's control.
     */
    ShipControl *control;

    /**
     * @brief damageObservers The ship's damage observers.
     */
    std::vector<Observer *> *damageObservers;
    /**
     * @brief afterDamageObservers The ship's after damage observers.
     */
    std::vector<Observer *> *afterDamageObservers;

    /**
     * @brief coreComponents The components in the core part.
     */
    std::vector<IComponent*> *coreComponents;
    /**
     * @brief bowComponents The components in the bow part.
     */
    std::vector<IComponent*> *bowComponents;
    /**
     * @brief starboardComponents The components in the starboard part.
     */
    std::vector<IComponent*> *starboardComponents;
    /**
     * @brief sternComponents The components in the stern part.
     */
    std::vector<IComponent*> *sternComponents;
    /**
     * @brief portComponents The components in the port part.
     */
    std::vector<IComponent*> *portComponents;

    /**
     * @brief addComponentToPart Add a component to a part.
     * @param component The component to add.
     * @param shipPart The part where you want to add the component.
     */
    void addComponentToPart(IComponent *component, constants::shipParts shipPart);

    /**
     * @brief sensors the ship's sensors.
     */
    std::vector<Sensor*> *sensors;
};

#endif // ABSTRACTSHIP_H
