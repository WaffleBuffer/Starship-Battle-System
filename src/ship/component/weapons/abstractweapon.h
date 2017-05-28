#ifndef ABSTRACTWEAPON_H
#define ABSTRACTWEAPON_H

/**
 * @file abstractweapon.h
 */

#include "../abstractcomponent.h"

/**
 * @brief The AbstractWeapon class. An abstract weapon. Lot to do here.
 */
class AbstractWeapon: public AbstractComponent
{
public:
    /**
     * @brief AbstractWeapon The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     */
    AbstractWeapon(const std::string & name, const std::string & description, IShip *ship);
};

#endif // ABSTRACTWEAPON_H
