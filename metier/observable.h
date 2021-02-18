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
class observable {
public:
    /*!
    * \brief Constructor.
    *
    * constructs an observable.
    */
    virtual ~observable();

    /*!
    * \brief adds a class that observs this one
    *
    * \param obs the observer to add
    */
    virtual void addObserver(observer obs);

    /*!
    * \brief notifies all the observers that a change was made
    *
    * this method will give an instance of the object self to
    * the observers, so that they can update according to the change
    *
    * \param message the message to send to the observer
    */
    virtual void notify(std::string message);
};

#endif // OBSERVABLE_H
