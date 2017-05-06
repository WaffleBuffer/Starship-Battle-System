#include "d6.h"

D6::D6()
{
    this->name = "D6";
}

int D6::roll() {
    int rolled = rand() % 6 + 1;
    this->lastValue = rolled;
    return rolled;
}

int D6::getMaxValue() {
    return 6;
}
