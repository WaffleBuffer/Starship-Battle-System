#include "basichull.h"

#include "iship.h"
#include "../ship/damage.h"

BasicHull::BasicHull(const int &maxPoints, IShip *ship)
    :AbstractHull(maxPoints, ship){

}

void BasicHull::notify(Observable *origin, MyObject *arg)
{
    IShip *ship = dynamic_cast<IShip*> (origin);
    if(ship == NULL) {
        return;
    }
    Damage *damage = dynamic_cast<Damage*>(arg);
    if(damage == NULL) {
        return;
    }

    this->setCurrentPoints(this->getCurrentPoints() - damage->getCurrentValue());
    if (this->getCurrentPoints() <= 0) {
        this->getShip()->destroy();
    }
}
