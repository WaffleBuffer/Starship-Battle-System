#include "iweapon.h"

IWeapon::IWeapon(const std::string &name, const std::string &description, IShip *ship)
    :AbstractComponent(name, description, ship){

}
