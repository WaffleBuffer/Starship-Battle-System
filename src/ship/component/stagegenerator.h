#ifndef STAGEGENERATOR_H
#define STAGEGENERATOR_H

#include "abstractgenerator.h"

#include <vector>

using namespace std;

class StageGenerator: public AbstractGenerator
{
public:
    StageGenerator(const string &name, const string &description, IShip *ship);

};

#endif // STAGEGENERATOR_H
