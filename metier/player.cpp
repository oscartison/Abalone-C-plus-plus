#include "player.h"
#include <stdexcept>
namespace abalone { namespace model {
Player::Player(int nb) :
    nb_ {(nb == 1 || nb == 2) ? nb : throw std::invalid_argument("Player must be 1 or 2.")},
    nbMarbles_ {14}
{}

void Player::deleteMarble() {
    nbMarbles_ -= 1;
}

}
}
