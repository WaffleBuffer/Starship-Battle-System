#include "team.h"
#include "../ship/iship.h"

Team::Team()
    :ships(new std::vector<IShip*>()){

}

Team::~Team()
{
    for (size_t i = 0; i < this->ships->size(); ++i) {
        delete(this->ships->at(i));
    }
    delete this->ships;
}

std::vector<IShip *> *Team::getShips()
{
    return this->ships;
}
