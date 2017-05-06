#include "d10.h"

D10::D10()
{
    this->name = "D10";
}

int D10::roll() {
    int rolled = rand() % 10 + 1;
    this->lastValue = rolled;
    return rolled;
}

int D10::getMaxValue() {
    return 10;
}
