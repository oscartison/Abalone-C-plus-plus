#include "position.h"
#include "algorithm"
#include <stdlib.h>

Position::Position(int x, int y, int z) :
    x_ {x},
    y_ {y},
    z_ {z}
{

}

bool Position::isPossiblePos(int size) {
    bool inside = x_ >= 0 && x_ < size && y_ >= 0 && y_ <  size && z_ >= 0 && z_ < size;
    int sum = (size/2)*3;
    bool possible = x_ + y_ + z_ == sum;
    return inside && possible;
}

void Position::move(int dx, int dy, int dz) {
    x_ += dx;
    y_ += dy;
    z_ += dz;
}

int Position::distance(Position po2) {
    return std::max({abs(x_ - po2.x()), abs(y_ - po2.y()), abs(z_ - po2.z())});
}
