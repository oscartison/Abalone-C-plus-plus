#include<game.h>
#include<testgame.h>
#include<catch.hpp>

namespace abalone {
namespace test {

#define private public;
TEST_CASE("Test on the game") {
    abalone::test::TestGame g = abalone::test::TestGame();

    SECTION("Simple Movement in line A1B1") {
        g.makeMove(abalone::model::Position(8,4,0),abalone::model::Position(8,3,1));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,3,1))->player()->nb() == 1 );
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,2,2))->player()->nb() == 1 );
    }


}
}

}
