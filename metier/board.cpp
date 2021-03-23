#include "board.h"
#include <array>

Board::Board(Player playerBlack, Player playerWhite) :
    marbles_ {},
    nbMarbles_ {28}


{
    for (auto x = 0; x < size(); x++) {
        for (auto y = 0; y < size(); y++) {
            for (auto z = 0; z < size(); z++) {
                if ((z == 0 && x > 4 && y > 4)
                        && (z == 1 && x > 3 && y > 3)
                        && (z == 2 && x > 3 && x < 7 && y > 3 && y < 7)) {
                    marbles_[x][y][z] = new Marble(playerWhite);
                } else if ((z == 8 && x < 5 && y < 5)
                           && (z == 7 && x < 6 && y < 6)
                           && (z == 6 && x < 5 && x > 1 && y > 1 && y < 5)) {
                    marbles_[x][y][z] = new Marble(playerBlack);
                }
            }
        }
    }
}

std::optional<Marble*> Board::marbleAtPosition(Position pos)  {
    return *marbles_[pos.x()+4][pos.y()+4][pos.z()+4];
}
