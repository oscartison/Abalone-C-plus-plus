#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <list>
#include <array>
#include <optional>
#include <marble.h>
#include <iostream>

/*!
 * \brief Class that represents a board in the game abalone.
 *
 * with the size of the board and
 * the position of all the marbles on the board, the game board is fully represented.
 */
class Board {

    /*!
    * \brief The size of the game board.
    *
    * This number is constant
    */
    const static int size_ = 9;

    /*!
    * \brief an array with all the marbles on the board
    */
    std::array<std::array<std::array<std::optional<Marble*>,size_>,size_>, size_> marbles_ ;

    /*!
    * \brief the amount of marbles on the board.
    */
    int nbMarbles_;

public :

    /*!
    * \brief Constructor.
    *
    * The size of the board is given. The amount of black and white
    * marbles will be set to 14. the marbles are set to the right position
    *
    * The size cannot be null.
    *
    * \param playerBlack the first player of the board
    *
    * \param playerWhite the second player of the board
    */
    Board(Player & playerBlack, Player & playerWhite);

    /*!
     * \brief getter for number of marbles
     *
     * \return amount of marbles
     */
    inline int nbMarbles();

    /*!
     * \brief getter for the size of the board
     *
     * \return size of the board
     */
    inline int size() const;

    /*!
     * \brief getter for the vector with the marbles on the board
     *
     * \return the vector with the marbles on the board
     */
    inline std::array<std::array<std::array<std::optional<Marble*>,size_>,size_>, size_> marbles() const;

    /*!
    * \brief checks for a marble at a certain position
    *
    * \param pos the position to check
    *
    * \return the marble at this position,
    * if there is no marble it returns null
    */
    Marble* marbleAtPosition(Position pos);

    /*!
    * \brief checks if a position is possible
    * according to the size of the board
    *
    * \param pos the position to check
    *
    * \return true if the position is possible, false otherwise
    */
    bool isPosPossible(Position pos);

    /*!
    * \brief checks for a player at a certain position
    *
    * \return the player at this position,
    * if there is no player it returns null
    */
    Player * playerAtPosition(Position pos) ;

    /*!
    * \brief deletes the marble at this position
    *
    * \param pos the position to delete
    */
    void deleteAtPos(Position pos);

    /*!
    * \brief makes a marble move from a certain position to another.
    *
    * \param posBegin the initial position of the marble.
    *
    * \param posEnd the position where the marble has to go
    */
    void changePosition(Position posBegin, Position posEnd);

    /*!
    * \brief makes a group of marbels move from a certain position to another.
    *
    *
    * \param posBeginFirst the initial position of the first marble of a group.
    *
    * \param posBeginLast the initial position of the last marble of a group.
    *
    * \param posEnd the position where the first marble has to go
    */
    void changePosition(Position posBeginFirst,Position posBeginLast, Position posEnd);

    std::string to_string(Board & board);

};

int Board::nbMarbles() {
    return nbMarbles_;
}

int Board::size() const {
    return size_;
}

std::array<std::array<std::array<std::optional<Marble*>,9>,9>, 9> Board::marbles() const {
    return marbles_;
}

#endif // BOARD_H
