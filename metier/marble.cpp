#include "marble.h"
#include <stdexcept>

Marble::Marble(Player & play) :
    player_ {&play}
{}
