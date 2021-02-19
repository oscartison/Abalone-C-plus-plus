#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <list>
#include <marble.h>
#include "observable.h"
#include "observer.h"

/*!
 * \brief Class that represents a board in the game abalone.
 *
 * with the size of the board and
 * the position of all the marbles on the board, the game board is fully represented.
 */
class board {

    /*!
    * \brief The size of the game board.
    *
    * This number is constant
    */
    const int size_;

    /*!
    * \brief a 2d array of pointers to the marbles of the game.
    * A marble at A1 will be located a board[0][0]
    */
    marble ***board_;

    /*!
    * \brief the amount of marbles on the board.
    */
    int nbMarbles_;

public:
    /*!
    * \brief Constructor.
    *
    * The size of the board is given. The amount of black and white
    * marbles will be set to 14. the marbles are set to the right position
    *
    * The size cannot be null.
    *
    * \param size size of the board
    *
    * \throw std::invalid_argument if size is null.
    */
    board(int size, player playerBlack, player playerWhite);

    /*!
     * \brief getter for number of marbles
     *
     * \return amount of marbles
     */
    int nbMarbles();


    /*!
     * \brief getter for the size of the board
     *
     * \return size of the board
     */
    int size() const;

    /*!
     * \brief getter for the 2d array with the marbles on the board
     *
     * \return the 2d array with the marbles on the board
     */
    marble*** marbles() const;

    /*!
    * \brief checks for a marble at a certain position
    *
    * \param pos the position to check
    *
    * \return the marble at this position,
    * if there is no marble it returns null
    */
    marble marbleAtPosition(position pos);

    /*!
    * \brief checks if a position is possible
    * according to the size of the board
    *
    * \param pos the position to check
    *
    * \return true if the position is possible, false otherwise
    */
    bool isPosPossible(position pos);

    /*!
    * \brief checks for a player at a certain position
    *
    * \return the player at this position,
    * if there is no player it returns null
    */
    player playerAtPosition(position pos);

    /*!
    * \brief deletes the marble at this position
    *
    * \param pos the position to delete
    */
    void deleteAtPos(position pos);

    /*!
    * \brief makes a marble move from a certain position to another.
    *
    * \param posBegin the initial position of the marble.
    *
    * \param posEnd the position where the marble has to go
    */
    void makeMove(position posBegin, position posEnd);

    /*!
    * \brief checks if a move is possible from a certain position to another.
    *
    * \param posBegin the initial position of the marble.
    *
    * \param posEnd the position where the marble has to go
    *
    * \return true if the move is possible,
    * false otherwise
    */
    bool isMovePossible(position posBegin, position posEnd);

    /*!
    * \brief makes a group of marvels move from a certain position to another.
    *
    *
    * \param posBeginFirst the initial position of the first marble of a group.
    *
    * \param posBeginLast the initial position of the last marble of a group.
    *
    * \param posEnd the position where the first marble has to go
    */
    void makeMove(position posBeginFirst,position posBeginLast, position posEnd);

    /*!
    * \brief checks if a move is possible from a certain position to another.
    *
    * \param posBeginFirst the initial position of the first marble of a group.
    *
    * \param posBeginLast the initial position of the last marble of a group.
    *
    * \param posEnd the position where the marble has to go
    *
    * \return true if the move is possible,
    * false otherwise
    */
    bool isMovePossible(position posBeginFirst,position posBeginLast, position posEnd);
};

#endif // BOARD_H
