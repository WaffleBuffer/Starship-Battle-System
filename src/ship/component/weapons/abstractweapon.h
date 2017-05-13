#ifndef IWEAPON_H
#define IWEAPON_H

#include "../abstractcomponent.h"

class AbstractWeapon: public AbstractComponent
{
public:
    AbstractWeapon(const std::string & name, const std::string & description, IShip *ship);
};

#endif // IWEAPON_H
