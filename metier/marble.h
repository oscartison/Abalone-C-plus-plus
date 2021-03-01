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


public:

    /*!
    * \brief Constructor.
    *
    * a marble is created with a player, it determines
    *
    * \param player the player whos marble it is.
    *
    * \throw std::invalid_argument if player is null.
    */
    marble(player play);


    /*!
     * \brief getter for the player of the marble
     *
     * \return the player of the marble
     */
    player player() const;


};

#endif // MARBLE_H
