#include "board.h"
#include <array>

Board::Board(Player & playerBlack, Player &playerWhite) :

    marbles_ {},
    nbMarbles_ {28}


{
    for (auto x = 0; x < size(); x++) {
        for (auto y = 0; y < size(); y++) {
            for (auto z = 0; z < size(); z++) {
                if(isPosPossible(Position(x,y,z))) {
                    if ((z == 0 && x >= 4 && y >= 4)
                            || (z == 1 && x >= 3 && y >= 3)
                            || (z == 2 && x > 3 && x < 7 && y > 3 && y < 7)) {
                        marbles_[x][y][z] =  new Marble(playerWhite);
                    } else if ((z == 8 && x < 5 && y < 5)
                               || (z == 7 && x < 6 && y < 6)
                               || (z == 6 && x < 5 && x > 1 && y > 1 && y < 5)) {
                        marbles_[x][y][z] = new Marble(playerBlack);
                    }
                }
            }
        }
    }
}

Marble* Board::marbleAtPosition(Position pos)  {
    if(isPosPossible(pos)){
        return (marbles_[pos.x()][pos.y()][pos.z()]) ? *marbles_[pos.x()][pos.y()][pos.z()]: NULL;
    }
    else {
        return NULL;
    }
}

Player * Board::playerAtPosition(Position pos)  {
    if(marbleAtPosition(pos)) {
        return marbleAtPosition(pos)->player();
    } else {
        return NULL;
    }
}

void Board::deleteAtPos(Position pos) {
    if(marbleAtPosition(pos)) {
        //delete (marbleAtPosition(pos));
        *marbles_[pos.x()][pos.y()][pos.z()] = NULL;
    }
}

bool Board::isPosPossible(Position pos) {
    return pos.isPossiblePos(size());
}

void Board::changePosition(Position posBegin, Position posEnd) {
    if(isPosPossible(posEnd)) {
        std::cout << marbleAtPosition(posBegin)->player()->nb() <<std::endl;
        marbles_[posEnd.x()][posEnd.y()][posEnd.z()] = marbles_[posBegin.x()][posBegin.y()][posBegin.z()];
        deleteAtPos(posBegin);
    } else {
        marbleAtPosition(posBegin)->player()->deleteMarble();
        deleteAtPos(posBegin);
    }
}

std::string Board::to_string(Board & board) {
    std::string output = "";
    output+="         __________\n";
    for (auto z = 0; z < size(); z++) {
        for (auto y = size() - 1; y >= 0; y--) {
            output+= "";
            for (auto x = 0; x < size(); x++) {
                Position pos = Position(x,y,z);
                if(board.isPosPossible(pos)) {
                    if(x == 4 && y == 8 && z ==0) {
                        output+="     I--/";
                    } else if (x == 3 && y == 8 && z ==1) {
                        output+="    H--/";
                    }else if (x == 2 && y == 8 && z ==2) {
                        output+="   G--/";
                    }else if (x == 1 && y == 8 && z ==3) {
                        output+="  F--/";
                    }else if (x == 0 && y == 8 && z ==4) {
                        output+=" E--<";
                    }else if (x == 0 && y == 7 && z ==5) {
                        output+="  D--\\";
                    }else if (x == 0 && y == 6 && z ==6) {
                        output+="   C--\\";
                    }else if (x == 0 && y == 5 && z ==7) {
                        output+="    B--\\";
                    }else if (x == 0 && y == 4 && z ==8) {
                        output+="     A--\\";
                    }else if (x == 0 && y == 3 && z ==1) {
                    }
                    if (board.playerAtPosition(pos)) {
                        output+= (board.playerAtPosition(pos)->nb() == 1) ? "o ":"x ";
                    }else {
                        output+= ". ";
                    }
                    if ((x == 8 || y == 0) && z < 4){
                        output += "\\ \n";
                    } else if (x == 8 || y == 0){
                        switch (z) {
                        case 5:
                            output += "/\\ \n";
                            break;
                        case 6:
                            output += "/\\ 9 \n";
                            break;
                        case 7:
                            output += "/\\ 8 \n";
                            break;
                        case 8:
                            output += "/\\ 7 \n";
                            break;
                        default:
                            output += ">\n";
                        }
                    }
                }
            }
        }
    }
    output += "         -\\-\\-\\-\\-\\  6 \n           1 2 3 4 5";
    output += "\n";

    return output;
}
