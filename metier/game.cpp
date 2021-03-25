#include "game.h"
#include "board.h"
#include <list>
#include <stdexcept>

Game::Game():
    list_observer_ {},
    playerWhite_ {Player(1)},
    playerBlack_ {Player(2)},
    playerTurn_ {&playerWhite()},
    gameBoard_ {Board(playerBlack(), playerWhite())},
    nbPlays_ {0}
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

std::string Game::to_string(const Game & game) {
    std::string str = "Player turn: ";
    std::string str2 = (game.playerTurn()->nb() == 1) ? "o" : "x";
    Board b = game.gameBoard_;
    return b.to_string(b) + "\n" + str + str2 + "\n";
}

std::ostream & operator<<(std::ostream & out, const Game & game) {
    Game g = game;
    return out << g.to_string(game);
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
        //if (isMovePossible(pos1,pos2,pos3)) {
        //  makeMove(pos1,pos2,pos3);
        //}
    }
}

void Game::makeMove(Position posBegin, Position posEnd) {
    if (gameBoard_.playerAtPosition(posBegin) && gameBoard_.playerAtPosition(posBegin)->nb() == playerTurn()->nb() && posBegin.distance(posEnd) == 1) {
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

        if (i<3 &&j==0) {
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
