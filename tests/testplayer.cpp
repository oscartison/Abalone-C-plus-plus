#include<player.h>
#include<catch.hpp>

namespace abalone {
namespace test {


TEST_CASE("Test on the player") {
    abalone::model::Player p = abalone::model::Player(2);

    SECTION("Test getters") {
       REQUIRE(p.nbMarbles() == 14);
       REQUIRE(p.nb() == 2);
    }

    SECTION("Test delete") {
       p.deleteMarble();
       REQUIRE(p.nbMarbles() == 13);
    }


}
}
}
