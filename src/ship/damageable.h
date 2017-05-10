#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

class Damage;

class Damageable
{
public:
    Damageable();
    virtual ~Damageable() {}
    virtual void getDamaged(Damage *damage) = 0;
};

#endif // DAMAGEABLE_H
