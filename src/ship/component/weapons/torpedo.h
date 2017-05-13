#ifndef TORPEDO_H
#define TORPEDO_H

#include "abstractweapon.h"

class Torpedo: public AbstractWeapon
{
public:
    Torpedo(const std::string & name, const std::string & description, IShip *ship);
};

#endif // TORPEDO_H
