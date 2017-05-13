#include "torpedo.h"

Torpedo::Torpedo(const std::string &name, const std::string &description, IShip *ship)
    :AbstractWeapon(name, description, ship){

}
