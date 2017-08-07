#ifndef ENERGYPROVIDABLE_H
#define ENERGYPROVIDABLE_H

/**
 * @file energyprovidable.h
 */

#include "abstractcomponent.h"

/**
 * @brief The EnergyProvidable class. A component that can be provided with energy. Abstract class.
 */
class EnergyProvidable: public AbstractComponent
{
public:
    /**
     * @brief EnergyProvidable The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy units that can be provided (it may not be a strict maximum).
     */
    EnergyProvidable(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    virtual ~EnergyProvidable() {}
    /**
     * @brief provideEnergy Provide some energy and activate the component.
     * @param energy The energy unit amount.
     */
    virtual void provideEnergy(const int & energy) = 0;
    /**
     * @brief getMaxEnergy Get the maximum amount of energy units that can be provided (it may not be a strict maximum).
     * @return The maximum amount of energy units that can be provided (it may not be a strict maximum).
     */
    unsigned int getMaxEnergy();

    /**
     * @brief saveXML Save the EnergyProvidable infos of an EnergyProvidable.
     * @param root The root xml tag that should contain this object.
     * @param componentToLoad The EnergyProvidable from which you want to save infos.
     */
    static void saveEnergyProvXML(pugi::xml_node &root, EnergyProvidable *componentToLoad);

    /**
     * @brief loadFromXML Load EnergyProvidable infos into an EnergyProvidable.
     * @param root The xml node that should contain the EnergyProvidable informations.
     * @param ship The ship that will use this EnergyProvidable.
     * @param componentToLoad The EnergyProvidable into which you want to save infos.
     */
    static void loadEnergyProvFromXML(IShip *ship, const pugi::xml_node &root, EnergyProvidable *componentToLoad);
private:
    /**
     * @brief maxEnergy The maximum amount of energy units that can be provided (it may not be a strict maximum).
     */
    unsigned int maxEnergy;
};

#endif // ENERGYPROVIDABLE_H
