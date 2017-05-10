#include "shield.h"

Shield::Shield(const std::string &name, const std::string &description, IShip *ship)
    :AbstractComponent(name, description, ship){

}
