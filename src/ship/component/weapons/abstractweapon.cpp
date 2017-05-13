#include "abstractweapon.h"

AbstractWeapon::AbstractWeapon(const std::string &name, const std::string &description, IShip *ship)
    :AbstractComponent(name, description, ship){

}
