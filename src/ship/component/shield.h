#ifndef SHIELD_H
#define SHIELD_H

/**
 * @file shield.h
 */

#include "abstractcomponent.h"

/**
 * @brief The Shield class. The shield that can absorbe some damage befor the hull (not yet implemented).
 */
class Shield: public AbstractComponent
{
public:
    /**
     * @brief Shield The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     */
    Shield(const std::string & name, const std::string & description, IShip *ship);
};

#endif // SHIELD_H
