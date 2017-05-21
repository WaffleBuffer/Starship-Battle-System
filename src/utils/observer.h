#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @file observer.h
 */

class MyObject;
class Observable;

/**
 * @brief The Observer class.
 */
class Observer
{
public:
    /**
     * @brief Observer The constructor. Does nothing.
     */
    Observer();
    virtual ~Observer();
    /**
     * @brief notify Notify this observer that the Observable has changed.
     * @param origin The changed observable
     * @param arg Some argument. Can be anything (but must be an object and not void* to check object type).
     */
    virtual void notify(Observable *origin, MyObject *arg) = 0;
};

#endif // OBSERVER_H
