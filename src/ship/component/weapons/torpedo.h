#ifndef TORPEDO_H
#define TORPEDO_H

/**
 *
 */

#include "abstractweapon.h"

/**
 * @brief The Torpedo class. A basic torpedo.
 */
class Torpedo: public AbstractWeapon
{
public:
    /**
     * @brief Torpedo The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     */
    Torpedo(const std::string & name, const std::string & description, IShip *ship);
};

#endif // TORPEDO_H
