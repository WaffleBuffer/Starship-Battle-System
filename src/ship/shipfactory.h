#ifndef SHIPFACTORY_H
#define SHIPFACTORY_H

#include<string>
#include<vector>

class PlayerControlledShip;
class Hull;
class Armor;
class Sensor;
class NavThruster;
class TranslationThruster;
class RotationThruster;
class IoController;

class ShipFactory
{
public:
    ShipFactory();
    PlayerControlledShip *buildTestShip(IoController *ioController);
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
