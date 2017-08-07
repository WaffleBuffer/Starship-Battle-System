#ifndef CONSOLEMENUITEMENERGY_H
#define CONSOLEMENUITEMENERGY_H

#include "consolemenuitem.h"

class EnergyProvidable;
class GameController;

class ConsoleMenuItemEnergy: public ConsoleMenuItem
{
public:
    ConsoleMenuItemEnergy(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component, GameController *gameController);

    virtual void action(std::vector<std::string> *args = nullptr) override;

private:
    EnergyProvidable *component;
    GameController *gameController;
};

#endif // CONSOLEMENUITEMENERGY_H
