#include<game.h>
#include<catch.hpp>

TEST_CASE("Test some moves on the board") {
    Player p1 = Player(1);
    Player p2 = Player(2);
    Board board = Board(p1,p2);

    SECTION("Simple Movement") {
        board.changePosition(Position(3,3,6), Position(4,4,4));
        REQUIRE_FALSE(board.marbleAtPosition(Position(3,3,6)));
        REQUIRE(board.playerAtPosition(Position(4,4,4))->nb() == 1);
    }

    SECTION("Move outside the board") {
        board.changePosition(Position(3,3,6), Position(4,4,9));
        REQUIRE_FALSE(board.marbleAtPosition(Position(3,3,6)));
        REQUIRE(board.playerAtPosition(Position(3,2,7))->nbMarbles() == 13);
    }

    SECTION("Is position possible") {
        REQUIRE(board.isPosPossible(Position(4,4,4)));
    }

    SECTION("Is position not possible") {
        REQUIRE_FALSE(board.isPosPossible(Position(7,2,4)));
    }

    SECTION("Check for marble at a certain position") {
        REQUIRE(board.marbleAtPosition(Position(3,3,6))->player()->nb() == 1);
    }

    SECTION("Check at a position without marble") {
        REQUIRE_FALSE(board.marbleAtPosition(Position(4,4,4)));
    }

    SECTION("Check for marble at impossible position") {
        REQUIRE_FALSE(board.marbleAtPosition(Position(7,7,7)));
    }

    SECTION("Check for player at position") {
        REQUIRE(board.playerAtPosition(Position(3,3,6))->nb() == 1);
    }

    SECTION("Check for [marble at impossible positionplayer at position without player") {
        REQUIRE_FALSE(board.playerAtPosition(Position(4,4,4)));
    }

    SECTION("checks if delete works") {
        board.deleteAtPos(Position(3,3,6));
        REQUIRE_FALSE(board.marbleAtPosition(Position(3,3,6)));
    }
}
