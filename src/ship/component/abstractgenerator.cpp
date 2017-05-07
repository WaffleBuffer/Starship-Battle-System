#include "abstractgenerator.h"

AbstractGenerator::AbstractGenerator(const std::string &name, const std::string &description, IShip *ship)
    :AbstractComponent(name, description, ship){

}
