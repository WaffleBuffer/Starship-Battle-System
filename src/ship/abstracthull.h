#ifndef HULL_H
#define HULL_H

#include <string>

class AbstractHull
{
public:
    AbstractHull(const int & maxPoints);
    std::string toString();
private:
    int maxPoints;
    int currentPoints;
};

#endif // HULL_H
