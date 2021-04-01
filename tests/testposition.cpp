#include<position.h>
#include<catch.hpp>

namespace abalone {
namespace test {


TEST_CASE("Test on position") {
    abalone::model::Position p1 = abalone::model::Position(4,4,4);
    abalone::model::Position p2 = abalone::model::Position(4,6,4);

    SECTION("Test getters") {
       REQUIRE(p1.x() == 4);
       REQUIRE(p1.y() == 4);
       REQUIRE(p1.z() == 4);
    }

    SECTION("Test isPossible") {
       REQUIRE(p1.isPossiblePos(9));
       REQUIRE_FALSE(p2.isPossiblePos(9));
    }

    SECTION("Test distance") {
       REQUIRE(p1.distance(abalone::model::Position(6,4,2)) == 2);
    }

    SECTION("Test - operator") {
        abalone::model::Position pResult = p1 - abalone::model::Position(1,2,3);
        REQUIRE(pResult.x()== 3);
        REQUIRE(pResult.y()== 2);
        REQUIRE(pResult.z()== 1);
    }

    SECTION("Test + operator") {
        abalone::model::Position pResult = p1 + abalone::model::Position(1,2,3);
        REQUIRE(pResult.x()== 5);
        REQUIRE(pResult.y()== 6);
        REQUIRE(pResult.z()== 7);
    }

    SECTION("Test abbaToPos") {
        abalone::model::Position pResult = abalone::model::abaToPos("A5");
        REQUIRE(pResult.x()== 4);
        REQUIRE(pResult.y()== 0);
        REQUIRE(pResult.z()== 8);
    }

    SECTION("Test abbaToPos not possible") {
        REQUIRE_THROWS(abalone::model::abaToPos("X5"));
         REQUIRE_THROWS(abalone::model::abaToPos("A9"));
    }

}
}
}
