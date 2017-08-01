#ifndef SHIPFACTORY_H
#define SHIPFACTORY_H

#include<string>
#include<vector>

class Ship;
class Hull;
class Armor;
class Sensor;
class NavThruster;
class TranslationThruster;
class RotationThruster;

class ShipFactory
{
public:
    ShipFactory();
    Ship *buildTestShip();
private:
    std::string name;
    std::string description;
    Hull *hull;
    Armor *armor;
    Sensor *sensor;
    NavThruster *forwardThruster;
    NavThruster *backThruster;
    TranslationThruster *leftTThruster;
    TranslationThruster *frontTThruster;
    TranslationThruster *rightTThruster;
    TranslationThruster *backTThruster;
    RotationThruster *rotationThruster;
};

#endif // SHIPFACTORY_H
