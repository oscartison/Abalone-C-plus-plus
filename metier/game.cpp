#include "game.h"
#include <list>

Game::Game() :
    list_observer_ {},
    playerWhite_ {Player(1)},
    playerBlack_ {Player(2)},
    playerTurn_ {&playerWhite()},
    gameBoard_ {Board(playerBlack(), playerWhite())},
    nbPlays_ {0}
{

}

void Game::notify(std::string message) {
    for (auto observer:list_observer()) {
        observer->update(this, message);
    }
}

void Game::addObserver(Observer obs) {
    list_observer().push_back(&obs);
}

bool Game::checkWon() {
    return playerWhite().nbMarbles() < 9 || playerBlack().nbMarbles() < 9;
}

void Game::changeTurn() {
        setTurn((playerTurn()->nb() == 1) ? playerBlack() : playerWhite());
}

void Game::setTurn(Player &player) {
    playerTurn_ = &player;
}
