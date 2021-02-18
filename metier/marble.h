#ifndef MARBLE_H
#define MARBLE_H

#include "player.h"
#include "position.h"

/*!
 * \brief Class that represents the marbles.
 *
 * a marbles contains the player that owns this marble,
 * it will determine its color.
 */
class marble {

    /*!
    * \brief The player whos marble it is.
    */
    const player player_;

    /*!
    * \brief the position of the marble on the board.
    */
    position positionMarble_;

public:

    /*!
    * \brief Constructor.
    *
    * a marble is created with a player, it determines
    *
    * \param player the player whos marble it is.
    *
    * \param pos the initial position of the marble
    *
    * \throw std::invalid_argument if player or position is null.
    */
    marble(player play, position pos);


    /*!
     * \brief getter for the player of the marble
     *
     * \return the player of the marble
     */
    player player() const;

    /*!
     * \brief getter for the position of the marble
     *
     * \return the position of the marble
     */
    position positionMarble() const;

    /*!
     * \brief getter for the player of the marble
     *
     * \param newPos the new position
     */
    void changePosition(position newPos);

};

#endif // MARBLE_H
