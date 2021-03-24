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
{
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



std::string Game::to_string(const Game & game) {
    Board b = game.gameBoard_;
    return b.to_string(b);
}

std::ostream & operator<<(std::ostream & out,
                          const Game & game) {
    Game g = game;
    return out << g.to_string(game);
}

void Game::stringToMovement(std::string s) {
    if(s.size() > 6 || s.size() < 4) {
        throw std::invalid_argument("not in ABA pro");
    }

}
