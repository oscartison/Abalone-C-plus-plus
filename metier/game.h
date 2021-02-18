#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "observable.h"

/*!
 * \brief Class that represents a the game
 *
 * this class is the current state of the game.
 */
class game: public observable {
    /*!
    * \brief  list with all the observers of this observable
    */
    std::list<observer *> list_observer_;

    /*!
    * \brief the actual board of the current game.
    */
    board gameBoard_;

    /*!
    * \brief The player with the white marbles
    */
    player playerWhite_;

    /*!
    * \brief The player with the black marbles
    */
    player playerBlack_;


    /*!
    * \brief The player that is playing for the moment
    */
    player playerTurn_;

public:
    /*!
    * \brief Constructor.
    *
    * a new game is created with a new board and new players
    *
    */
    game();

    /*!
    * \brief Constructor.
    *
    * a new game is created with a new board and new players
    *
    */
    void notify(std::string message) override;

    /*!
     * \brief getter for the player whos turn it is
     *
     * \return the player whos turn it is.
     */
    player playerTurn() const;

    /*!
     * \brief getter for the board of the game
     *
     * \return the board of the game
     */
    player gameBoard() const;


    /*!
     * \brief getter for the player that is playing with the white marbles
     *
     * \return the player that is playing with the white marbles
     */
    player playerWhite() const;

    /*!
     * \brief getter for the player that is playing with the black marbles
     *
     * \return the player that is playing with the black marbles
     */
    player playerBlack() const;

    /*!
     * \brief checks if someone won the game.
     *
     * \return true if a player won, false otherwise.
     *
     * a player won if the other has lost 6 marbles.
     */
    bool checkWon() const;

    /*!
    * \brief makes a marble move from a certain position to another. The move can
    * anly be made if it is possible and if the player whos turn it is tries to
    * move a marble of his own color.
    *
    *
    * \param posBeginFirst the initial position of the first marble of a group.
    *
    * \param posBeginLast the initial position of the last marble of a group.
    *
    * \param posEnd the position where the first marble has to go
    */
    void makeMove(position posBegin,
                  position posEnd);

    /*!
    * \brief makes a group of marvels move from a certain position to another. The move can
    * anly be made if it is possible and if the player whos turn it is tries to
    * move a group of marbles of his own color.
    *
    *
    * \param posBeginFirst the initial position of the first marble of a group.
    *
    * \param posBeginLast the initial position of the last marble of a group.
    *
    * \param posEnd the position where the first marble has to go
    */
    void makeMove(position posBeginFirst,
                  position posBeginLast,
                  position posEndFirst);

    /*!
     * \brief chamges whos turn it is to play.
     */
    void changeTurn();
};

#endif // GAME_H
