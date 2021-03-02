#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include "observable.h"

/*!
 * \brief abstract Class that defines an observer class
 *
 * an observer class is a class that will be updated when he
 * is notified by the observable that a change was made.
 */
class Observer {
public:

    /*!
    * \brief Constructor.
    *
    * constructs an observer.
    */
    virtual ~Observer();

    /*!
    * \brief updates the observer
    *
    * this method will update the state of the observer according
    * to the new state of the observable
    *
    * \param obs the observable that notified the observer.
    *
    * \param message the message sent by the observable
    *
    */
    virtual void update(Observable obs,std::string message) = 0;
};

#endif // OBSERVER_H
