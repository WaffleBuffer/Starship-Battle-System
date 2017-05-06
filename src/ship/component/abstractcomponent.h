#ifndef ABSTRACTCOMPONENT_H
#define ABSTRACTCOMPONENT_H

#include "../iship.h"

#include <string>

using namespace std;

class AbstractComponent
{
public:
    AbstractComponent();
private:
    string name;
    string description;
    IShip *ship;
};

#endif // ABSTRACTCOMPONENT_H
