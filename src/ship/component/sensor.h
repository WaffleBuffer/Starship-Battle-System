#ifndef SENSOR_H
#define SENSOR_H

#include "abstractcomponent.h"

class Sensor: public AbstractComponent
{
public:
    Sensor(const std::string & name, const std::string & description, IShip *ship, const int & maxLevel);

    std::string toString() override;
private:
    int currentLevel;
    const int maxLevel;
};

#endif // SENSOR_H
