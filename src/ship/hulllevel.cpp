#include "hulllevel.h"

HullLevel::HullLevel(const int &hullQuality)
    :hullQuality(hullQuality){

}

std::string HullLevel::toString()
{
    std::string res = "";
    res += std::to_string(this->hullQuality);
    return res;
}

int HullLevel::getHullQuality() const
{
    return hullQuality;
}
