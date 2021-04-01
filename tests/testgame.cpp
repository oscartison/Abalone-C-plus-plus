#include<game.h>
#include<testgame.h>
#include<catch.hpp>

namespace abalone { namespace test {

TEST_CASE("Test on the game") {
    abalone::test::TestGame g = abalone::test::TestGame();

    SECTION("Movement of a non-existent marble at position (0, 0, 0)") {
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(4,4,4), abalone::model::Position(4,4,5)));
    }

    SECTION("Impossible movement") {
        REQUIRE_THROWS(g.stringToMovement("I5E9"));
    }

    SECTION("Move an opponent's marble") {
        REQUIRE_THROWS(g.isMovePossible(abalone::model::Position(4,0,8)));
        REQUIRE_THROWS(g.isMovePossible(abalone::model::Position(4,0,8),abalone::model::Position(5,0,7)));
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(4,0,8),abalone::model::Position(5,0,7)));
    }

    SECTION("The player moves his own marbles") {
        REQUIRE(g.isMovePossible(abalone::model::Position(4,8,0)));
        REQUIRE(g.isMovePossible(abalone::model::Position(4,8,0),abalone::model::Position(3,8,1)));
    }

    SECTION("Test stringToMovement with simple movement") {
        g.stringToMovement("I9H9");
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,3,1))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,2,2))->player()->nb() == 1);
    }

    SECTION("Test stringToMovement with not ABA-Pro") {
        REQUIRE_THROWS(g.stringToMovement("abalone"));
    }

    SECTION("Simple movement of 1 marble") {
        g.makeMove(abalone::model::Position(8,3,1),abalone::model::Position(7,3,2));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(7,3,2))->player()->nb() == 1);
        REQUIRE_FALSE(g.getBoard().marbleAtPosition(abalone::model::Position(8,3,1))->player()->nb() == 1);
    }

    SECTION("Simple movement of 2 marbles") {
        g.makeMove(abalone::model::Position(8,4,0),abalone::model::Position(8,3,1));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,3,1))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(8,2,2))->player()->nb() == 1);
    }

    SECTION("Simple movement of 3 marbles") {
        g.makeMove(abalone::model::Position(4,8,0),abalone::model::Position(4,7,1));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,7,1))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,6,2))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
    }

    SECTION("Impossible movement of 4 marbles") {
        g.makeMove(abalone::model::Position(7,4,1),abalone::model::Position(7,3,2));
        g.makeMove(abalone::model::Position(5,0,7),abalone::model::Position(6,0,6));
        g.makeMove(abalone::model::Position(7,3,2),abalone::model::Position(7,2,3));
        g.makeMove(abalone::model::Position(6,0,6),abalone::model::Position(6,1,5));
        g.makeMove(abalone::model::Position(7,2,3),abalone::model::Position(6,3,3));
        g.makeMove(abalone::model::Position(6,1,5),abalone::model::Position(6,2,4));
        g.makeMove(abalone::model::Position(6,6,0),abalone::model::Position(6,5,1));
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(6,6,0),abalone::model::Position(6,5,1)));
    }

    SECTION("Impossible movement 1 vs 1") {
        g.makeMove(abalone::model::Position(3,8,1),abalone::model::Position(3,7,2)); // o
        g.makeMove(abalone::model::Position(3,3,6),abalone::model::Position(3,4,5)); // x
        g.makeMove(abalone::model::Position(3,7,2),abalone::model::Position(3,6,3)); // o
        g.makeMove(abalone::model::Position(3,4,5),abalone::model::Position(3,5,4)); // x
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(3,6,3), abalone::model::Position(3,5,4))); // o
    }

    SECTION("Movement 2 vs 1") {
        g.makeMove(abalone::model::Position(5,6,1),abalone::model::Position(5,5,2)); // o
        g.makeMove(abalone::model::Position(5,0,7),abalone::model::Position(5,1,6)); // x
        g.makeMove(abalone::model::Position(5,5,2),abalone::model::Position(5,4,3));
        g.makeMove(abalone::model::Position(5,1,6),abalone::model::Position(5,2,5));
        g.makeMove(abalone::model::Position(5,4,3),abalone::model::Position(5,3,4));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,3,4))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,2,5))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,1,6))->player()->nb() == 2);
    }

    SECTION("Movement 3 vs 1") {
        g.makeMove(abalone::model::Position(5,7,0),abalone::model::Position(5,6,1));
        g.makeMove(abalone::model::Position(5,0,7),abalone::model::Position(5,1,6));
        g.makeMove(abalone::model::Position(5,6,1),abalone::model::Position(5,5,2));
        g.makeMove(abalone::model::Position(5,1,6),abalone::model::Position(5,2,5));
        g.makeMove(abalone::model::Position(5,5,2),abalone::model::Position(5,4,3));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,4,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,3,4))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,2,5))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,1,6))->player()->nb() == 2);
    }

    SECTION("Impossible movement 2 vs 2") {
        g.makeMove(abalone::model::Position(4,7,1),abalone::model::Position(4,6,2));
        g.makeMove(abalone::model::Position(4,1,7),abalone::model::Position(4,2,6));
        g.makeMove(abalone::model::Position(4,6,2),abalone::model::Position(4,5,3));
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(4,2,6),abalone::model::Position(4,3,5)));
    }

    SECTION("Movement 3 vs 2") {
        g.makeMove(abalone::model::Position(4,8,0),abalone::model::Position(4,7,1));
        g.makeMove(abalone::model::Position(4,1,7),abalone::model::Position(4,2,6));
        g.makeMove(abalone::model::Position(4,7,1),abalone::model::Position(4,6,2));
        g.makeMove(abalone::model::Position(4,0,8),abalone::model::Position(5,0,7));
        g.makeMove(abalone::model::Position(4,6,2),abalone::model::Position(4,5,3));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,4,4))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,3,5))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,2,6))->player()->nb() == 2);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,1,7))->player()->nb() == 2);
    }

    SECTION("Impossible movement 3 vs 3") {
        g.makeMove(abalone::model::Position(4,8,0),abalone::model::Position(4,7,1));
        g.makeMove(abalone::model::Position(4,0,8),abalone::model::Position(4,1,7));
        g.makeMove(abalone::model::Position(4,7,1),abalone::model::Position(4,6,2));
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(4,1,7),abalone::model::Position(4,2,6)));
    }

    SECTION("Test stringToMovement with movement of a horizontal line of 2 marbles") {
        g.stringToMovement("G5G6F4");
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(3,6,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
    }

    SECTION("Test stringToMovement with movement of a horizontal line of 3 marbles") {
        g.stringToMovement("G5G7F5");
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,4,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(6,3,3))->player()->nb() == 1);
    }

    SECTION("Test stringToMovement with impossible movement of a horizontal line of 4 marbles") {
        g.stringToMovement("G5G7F5");
        REQUIRE_THROWS(g.stringToMovement("H4H7G3"));
    }

    SECTION("Movement of a horizontal line of 2 marbles") {
        g.makeMove(abalone::model::Position(4,6,2),abalone::model::Position(5,5,2),abalone::model::Position(4,5,3));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,4,3))->player()->nb() == 1);
    }

    SECTION("Movement of a horizontal line of 3 marbles") {
        g.makeMove(abalone::model::Position(4,6,2),abalone::model::Position(6,4,2),abalone::model::Position(3,6,3));
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(3,6,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(4,5,3))->player()->nb() == 1);
        REQUIRE(g.getBoard().marbleAtPosition(abalone::model::Position(5,4,3))->player()->nb() == 1);
    }

    SECTION("Impossible movement of a horizontal line of 4 marbles") {
        g.makeMove(abalone::model::Position(4,6,2),abalone::model::Position(5,5,2));
        g.makeMove(abalone::model::Position(4,0,8),abalone::model::Position(5,0,7));
        g.makeMove(abalone::model::Position(5,5,2),abalone::model::Position(6,4,2));
        g.makeMove(abalone::model::Position(5,0,7),abalone::model::Position(6,0,6));
        REQUIRE_THROWS(g.makeMove(abalone::model::Position(3,8,1),abalone::model::Position(6,5,1), abalone::model::Position(2,8,2)));
    }

    SECTION("Marble out") {
        g.stringToMovement("I5H5");
        g.stringToMovement("A1B1");
        g.stringToMovement("H5G5");
        g.stringToMovement("B1C1");
        g.stringToMovement("G5F5");
        g.stringToMovement("C5C6");
        g.stringToMovement("F5E5");
        g.stringToMovement("C1D1");
        g.stringToMovement("E5D5");
        REQUIRE(g.playerTurn()->nbMarbles() == 13);
    }

    SECTION("Checks if a player has won") {
        g.makeMove(abalone::model::Position(3,8,1),abalone::model::Position(4,7,1));
        g.makeMove(abalone::model::Position(0,5,7),abalone::model::Position(1,4,7));
        g.makeMove(abalone::model::Position(4,7,1),abalone::model::Position(5,6,1));
        g.makeMove(abalone::model::Position(1,4,7),abalone::model::Position(2,3,7));
        g.makeMove(abalone::model::Position(5,6,1),abalone::model::Position(6,5,1));
        g.makeMove(abalone::model::Position(2,3,7),abalone::model::Position(3,2,7));
        g.makeMove(abalone::model::Position(6,5,1),abalone::model::Position(7,4,1));
        g.makeMove(abalone::model::Position(3,2,7),abalone::model::Position(4,1,7));
        g.makeMove(abalone::model::Position(7,4,1),abalone::model::Position(8,3,1));
        g.makeMove(abalone::model::Position(4,1,7),abalone::model::Position(5,0,7));
        g.makeMove(abalone::model::Position(4,8,0),abalone::model::Position(5,7,0));
        //g.makeMove(abalone::model::Position(0,4,8),abalone::model::Position(1,3,8));
        REQUIRE(g.checkWon());
    }

    SECTION("Test if no one has won yet") {
        REQUIRE_FALSE(g.checkWon());
    }

    SECTION("Checks if the board is clean at the end") {
        g.makeMove(abalone::model::Position(3,8,1),abalone::model::Position(4,7,1));
        g.makeMove(abalone::model::Position(0,5,7),abalone::model::Position(1,4,7));
        g.makeMove(abalone::model::Position(4,7,1),abalone::model::Position(5,6,1));
        g.makeMove(abalone::model::Position(1,4,7),abalone::model::Position(2,3,7));
        g.makeMove(abalone::model::Position(5,6,1),abalone::model::Position(6,5,1));
        g.makeMove(abalone::model::Position(2,3,7),abalone::model::Position(3,2,7));
        g.makeMove(abalone::model::Position(6,5,1),abalone::model::Position(7,4,1));
        g.makeMove(abalone::model::Position(3,2,7),abalone::model::Position(4,1,7));
        g.makeMove(abalone::model::Position(7,4,1),abalone::model::Position(8,3,1));
        g.makeMove(abalone::model::Position(4,1,7),abalone::model::Position(5,0,7));
        g.makeMove(abalone::model::Position(4,8,0),abalone::model::Position(5,7,0));
        g.cleanBoard();
        bool marbleAtPosition = false;
        for(auto x = 0; x < g.getBoard().size(); x++) {
            for (auto y = 0; y < g.getBoard().size(); y++) {
                for (auto z = 0; z < g.getBoard().size(); z++) {
                    abalone::model::Position posToCheck = abalone::model::Position(x,y,z);
                    if (g.getBoard().marbleAtPosition(posToCheck)) {
                        marbleAtPosition = true;
                    }
                }
            }
        }
        REQUIRE_FALSE(marbleAtPosition);
    }

    SECTION("Checks if the board isn't clean during the game") {
        //g.cleanBoard();
        bool marbleAtPosition = false;
        for(auto x = 0; x < g.getBoard().size(); x++) {
            for (auto y = 0; y < g.getBoard().size(); y++) {
                for (auto z = 0; z < g.getBoard().size(); z++) {
                    abalone::model::Position posToCheck = abalone::model::Position(x,y,z);
                    if (g.getBoard().marbleAtPosition(posToCheck)) {
                        marbleAtPosition = true;
                    }
                }
            }
        }
        REQUIRE(marbleAtPosition);
    }

}}}

