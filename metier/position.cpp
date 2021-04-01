#include "position.h"
#include "algorithm"
#include <stdlib.h>

namespace abalone { namespace model {

Position::Position(int x, int y, int z) :
    x_ {x},
    y_ {y},
    z_ {z}
{}

bool Position::isPossiblePos(int size) {
    bool inside = x_ >= 0 && x_ < size && y_ >= 0 && y_ <  size && z_ >= 0 && z_ < size;
    int sum = (size/2)*3;
    bool possible = x_ + y_ + z_ == sum;
    return inside && possible;
}

int Position::distance(Position po2) {
    return std::max({abs(x_ - po2.x()), abs(y_ - po2.y()), abs(z_ - po2.z())});
}

Position operator+(const Position p1, const Position p2) {
    return Position(p1.x()+p2.x(),p1.y()+p2.y(),p1.z()+p2.z());
}

Position operator-(const Position p1, const Position p2) {
    return Position(p1.x()-p2.x(),p1.y()-p2.y(),p1.z()-p2.z());
}

Position abaToPos(std::string string) {
    char charPart = string[0];
    int intPart = string[1] - 48;
    Position posBegin {Position(4,4,4)};

    if (charPart < 'J' &&  charPart >= 'A' && intPart > 0 && intPart < 10) {
        char charBegin {'E'};
        int intBegin {5};
        int charDif = charBegin - charPart;
        int intDif = intBegin - intPart;

        for (int i = 0; i < abs(charDif);i++) {
            if (charDif < 0) {
                posBegin = posBegin + Position(0,1,-1);
            } else if (charDif > 0){
                posBegin = posBegin + Position(0,-1,1);
            }
        }

        for (int i = 0; i < abs(intDif); i++) {
            if (intDif < 0) {
                posBegin = posBegin + Position(1,-1,0);
            } else if (intDif > 0) {
                posBegin = posBegin + Position(-1,1,0);
            }
        }

        if (!posBegin.isPossiblePos(9)) {
            throw std::invalid_argument("Position not on the board");
        }

    } else {
        throw std::invalid_argument("Position not on the board");
    }

    return posBegin;
}

}}
