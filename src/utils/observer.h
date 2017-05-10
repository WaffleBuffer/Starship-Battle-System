#ifndef OBSERVER_H
#define OBSERVER_H

class MyObject;
class Observable;

class Observer
{
public:
    Observer();
    virtual ~Observer();
    virtual void notify(Observable *origin, MyObject *arg) = 0;
};

#endif // OBSERVER_H
