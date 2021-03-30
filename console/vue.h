#ifndef VUE_H
#define VUE_H
#include "observer.h"
#include "game.h"

//class Game;

namespace abalone {
namespace view{


/*!
 * \brief console observer of the class model::Game.
 */
class Vue final : public Observer {

    /*! \brief the observed class. */
    model::Game * subject_;

public :

    /*!
     * \brief constructor.
     *
     * This constructor registers itself as observer of the paramater.
     *  At the end the class is updated
     *
     * \param observable the address of the observed game
     */
    Vue(model::Game * observable);

    /*!
     * \brief destructor.
     *
     * when this object is deleted, it is first unregistered as observer.
     */
    virtual ~Vue();

    /*!
     * \brief updates the observer by printing the gameboard and whos turn it is.
     *
     * \param subject the game that notified a change was made
     */
    virtual void update(const Observable * subject) override;

    void printGame();

    void printWin();

};

}
}

#endif // VUE_H
