#include<game.h>
#include<catch.hpp>

TEST_CASE("Test on the game") {
    Game g = Game();

    SECTION("Simple Movement in line A1B1") {
        g.makeMove(Position(0,4,8),Position(0,5,7));
        //REQUIRE_FALSE(g.);
        // REQUIRE(board.playerAtPosition(Position(4,4,4))->nb() == 1);
    }

}
