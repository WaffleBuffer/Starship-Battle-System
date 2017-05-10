#ifndef SHIELD_H
#define SHIELD_H

#include "abstractcomponent.h"

class Shield: public AbstractComponent
{
public:
    Shield(const std::string & name, const std::string & description, IShip *ship);
};

#endif // SHIELD_H
