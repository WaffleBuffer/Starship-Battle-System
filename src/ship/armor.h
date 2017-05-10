#ifndef ARMOR_H
#define ARMOR_H

#include "../utils/observer.h"

#include <string>

class Armor: public Observer
{
public:
    Armor(const int & bowMax, const int & starMax, const int & sternMax, const int & portMax);
    void notify(Observable *origin, MyObject *arg) override;
    std::string toString();
private:
    int bowMax;
    int bowCurrentValue;
    int starBoardMax;
    int starBoardCurrentValue;
    int sternMax;
    int sternCurrentValue;
    int portMax;
    int portCurrentValue;
};

#endif // ARMOR_H
