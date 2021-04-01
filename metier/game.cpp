#include "game.h"
#include "board.h"
#include <list>
#include <stdexcept>

namespace abalone { namespace model {

Game::Game():
    list_observer_ {},
    playerWhite_ {Player(1)},
    playerBlack_ {Player(2)},
    playerTurn_ {&playerWhite()},
    gameBoard_ {Board(playerBlack(), playerWhite())}
{}

bool Game::checkWon() {
    return playerWhite().nbMarbles() < 9 || playerBlack().nbMarbles() < 9;
}

void Game::changeTurn() {
    setTurn((playerTurn()->nb() == 1) ? playerBlack() : playerWhite());
}

void Game::setTurn(Player &player) {
    playerTurn_ = &player;
}

void Game::stringToMovement(std::string s) {
    if (s.size() != 6 && s.size() != 4) {
        throw std::invalid_argument("Not in ABA-pro !");
    }

    if (s.size() == 4) {
        Position pos1 = abaToPos(s.substr(0,2));
        Position pos2 = abaToPos(s.substr(2,2));
        makeMove(pos1,pos2);
    } else {
        Position pos1 = abaToPos(s.substr(0,2));
        Position pos2 = abaToPos(s.substr(2,2));
        Position pos3 = abaToPos(s.substr(4,2));
        makeMove(pos1,pos2,pos3);
    }
}

bool Game::isMovePossible(Position posBegin) {
    if (gameBoard_.playerAtPosition(posBegin) &&
            gameBoard_.playerAtPosition(posBegin)->nb() == playerTurn()->nb()) {
        return true;
    } else {
        throw std::invalid_argument("Please select your own marbles");
    }
}

bool Game::isMovePossible(Position posBeginFirst, Position posBeginLast) {
    if (gameBoard_.playerAtPosition(posBeginFirst) &&
            gameBoard_.playerAtPosition(posBeginFirst)->nb() == playerTurn()->nb() &&
            gameBoard_.playerAtPosition(posBeginLast) &&
            gameBoard_.playerAtPosition(posBeginLast)->nb() == playerTurn()->nb()) {
        if (posBeginFirst.distance(posBeginLast) == 2) {
            Position middle = Position((posBeginFirst.x()+posBeginLast.x()) / 2,
                                       (posBeginFirst.y()+posBeginLast.y()) / 2,
                                       (posBeginFirst.z()+posBeginLast.z()) / 2);
            return (gameBoard_.playerAtPosition(middle) &&
                    gameBoard_.playerAtPosition(middle)->nb() == playerTurn()->nb())
                    ?
                        true:
                        throw std::invalid_argument("Please select your own marbles");
        } else {
            return true;
        }

    } else {
        throw std::invalid_argument("Please select your own marbles");
    }
}

void Game::makeMove(Position posBegin, Position posEnd) {
    if (isMovePossible(posBegin) && posBegin.distance(posEnd) == 1) {
        Position direction =  posEnd - posBegin;
        Position nextPos = posEnd;
        Position posForPlayer = posEnd;
        auto i = 0;
        auto j = 0;

        while (gameBoard_.playerAtPosition(nextPos))  {
            if (gameBoard_.playerAtPosition(nextPos)->nb() != playerTurn()->nb()) {
                if (j==0) {
                    posForPlayer = nextPos;
                }
                j++;
            } else {
                i++;
            }
            nextPos = nextPos + direction;
        }

        if (i<3 && j==0) {
            gameBoard_.changePosition(posBegin,nextPos);
            changeTurn();
            notifyObservers();
        } else if (j<=i) {
            gameBoard_.changePosition(posForPlayer,nextPos);
            gameBoard_.changePosition(posBegin,posForPlayer);
            changeTurn();
            notifyObservers();
        } else throw std::invalid_argument("Illegal movement !");
    } else throw std::invalid_argument("Illegal movement !");
}

void Game::makeMove(Position posBeginFirst, Position posBeginLast, Position posEndFirst) {
    if (isMovePossible(posBeginFirst,posBeginLast)) {
        Position movement = posBeginFirst - posEndFirst;
        if (posBeginFirst.distance(posBeginLast) == 1) {
            if (!gameBoard_.marbleAtPosition(posEndFirst) &&
                    !gameBoard_.marbleAtPosition(posBeginLast-movement)) {
                gameBoard_.changePosition(posBeginFirst,posEndFirst);
                gameBoard_.changePosition(posBeginLast,posBeginLast-movement);
                changeTurn();
                notifyObservers();
            }
        } else if (posBeginFirst.distance(posBeginLast) == 2) {
            Position middle = Position((posBeginFirst.x()+posBeginLast.x()) / 2,
                                       (posBeginFirst.y()+posBeginLast.y()) / 2,
                                       (posBeginFirst.z()+posBeginLast.z()) / 2);
            if (!gameBoard_.marbleAtPosition(posEndFirst) &&
                    !gameBoard_.marbleAtPosition(posBeginFirst-movement) &&
                    !gameBoard_.marbleAtPosition(middle-movement)) {
                gameBoard_.changePosition(posBeginFirst,posEndFirst);
                gameBoard_.changePosition(middle,middle-movement);
                gameBoard_.changePosition(posBeginLast,posBeginLast-movement);
                changeTurn();
                notifyObservers();
            }
        } else {
            throw std::invalid_argument("Positions are not in reglementary distance of each other");
        }
    }
}

void Game::cleanBoard() {
    if (checkWon()) {
        for (auto x = 0; x<gameBoard_.size(); x++) {
            for (auto y = 0; y < gameBoard_.size(); y++) {
                for (auto z = 0; z < gameBoard_.size(); z++) {
                    Position posToDelete = Position(x,y,z);
                    if (gameBoard_.marbleAtPosition(posToDelete)) {
                        gameBoard_.deleteAtPos(posToDelete);
                    }
                }
            }
        }
    }
}

}}
