#ifndef IWEAPON_H
#define IWEAPON_H

#include "../abstractcomponent.h"

class IWeapon: public AbstractComponent
{
public:
    IWeapon(const std::string & name, const std::string & description, IShip *ship);
};

#endif // IWEAPON_H
