#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "observer.h"

/*!
 * \brief abstract Class that defines an observable class
 *
 * an observable class is a class that will notify his observers
 * that a change was
 */
class Observable {
public:
    /*!
    * \brief Constructor.
    *
    * constructs an observable.
    */
    virtual ~Observable();

    /*!
    * \brief adds a class that observs this one
    *
    * \param obs the observer to add
    */
    virtual void addObserver(Observer obs) = 0;

    /*!
    * \brief notifies all the observers that a change was made
    *
    * this method will give an instance of the object self to
    * the observers, so that they can update according to the change
    *
    * \param message the message to send to the observer
    */
    virtual void notify(std::string message) = 0;
};

#endif // OBSERVABLE_H
