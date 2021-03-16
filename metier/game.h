#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "observable.h"

/*!
 * \brief Class that represents a the game
 *
 * this class is the current state of the game.
 */
class Game: public Observable {
    /*!
    * \brief  list with all the observers of this observable
    */
    std::list<Observer *> list_observer_;

    /*!
    * \brief The player with the white marbles
    */
    Player playerWhite_;

    /*!
    * \brief The player with the black marbles
    */
    Player playerBlack_;


    /*!
    * \brief The player that is playing for the moment
    */
    Player playerTurn_;

    /*!
    * \brief the actual board of the current game.
    */
    Board gameBoard_;

    /*!
    * \brief The number of marbles that where moved during this turn
    */
    int nbPlays_;

public:
    /*!
    * \brief Constructor.
    *
    * a new game is created with a new board and new players
    */
    Game();

    /*!
    * \brief notifies all the observers that a change was made
    *
    * this method will give an instance of the object self to
    * the observers, so that they can update according to the change
    *
    * \param message the message to send to the observer
    */
    void notify(std::string message) override;

    /*!
    * \brief adds a class that observs this one
    *
    * \param obs the observer to add
    */
    void addObserver(Observer obs) override;

    inline std::list<Observer *> list_observer();

    /*!
     * \brief getter for the player whos turn it is
     *
     * \return the player whos turn it is.
     */
    inline Player playerTurn() const;

    /*!
     * \brief getter for the number of marbles moved
     *
     * \return the ammount of marbles moved during this turn.
     */
    inline int nbPlays() const;


    /*!
     * \brief getter for the player that is playing with the white marbles
     *
     * \return the player that is playing with the white marbles
     */
    inline Player playerWhite() const;

    /*!
     * \brief getter for the player that is playing with the black marbles
     *
     * \return the player that is playing with the black marbles
     */
    inline Player playerBlack() const;

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
    void makeMove(Position posBegin,
                  Position posEnd);

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
    void makeMove(Position posBeginFirst,
                  Position posBeginLast,
                  Position posEndFirst);

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
    bool isMovePossible(Position posBegin, Position posEnd);

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
    bool isMovePossible(Position posBeginFirst,Position posBeginLast, Position posEnd);

    /*!
     * \brief changes whos turn it is to play.
     */
    void changeTurn();
};

Player Game::playerTurn() const {
    return playerTurn_;
}

int Game::nbPlays() const {
    return nbPlays_;
}

Player Game::playerWhite() const {
    return playerWhite_;
}


Player Game::playerBlack() const {
    return playerBlack_;
}

std::list<Observer *> Game::list_observer() {
    return list_observer_;
}

#endif // GAME_H
