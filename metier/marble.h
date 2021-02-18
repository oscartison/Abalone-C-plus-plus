#ifndef MARBLE_H
#define MARBLE_H

#include "player.h"
#include "position.h"

/*!
 * \brief Class that represents a board in the game abalone.
 *
 * with the size of the board and
 * the position of all the marbles on the board, the game board is fully represented.
 */
class marble {
    const player player_;
    position positionMarble_;

public:
    marble(player play, position pos);

    player player() const;
    position positionMarble() const;

    void changePosition(position newPos);

};

#endif // MARBLE_H
