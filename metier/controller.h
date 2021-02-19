#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "game.h"

/*!
 * \brief Class that represents a controller in the game abalone.
 *
 * the controller controls the start of the game.
 */
class controller {
    /*!
    * \brief the current game that is being played.
    */
    game game_;

public:
    /*!
    * \brief Constructor.
    *
    * a new game is created.
    */
    controller();


    /*!
    * \brief starts the game
    */
    void startGame();
};

#endif // CONTROLLER_H
