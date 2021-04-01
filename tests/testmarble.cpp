#include<catch.hpp>
#include<marble.h>

namespace abalone { namespace test {

TEST_CASE("Test on a marble") {

    abalone::model::Player p = abalone::model::Player(1);
    abalone::model::Marble m = abalone::model::Marble(p);

    SECTION("test the getter") {
        REQUIRE(m.player()->nb() == p.nb());
    }

}

}}
