#include "ember/sysutils/em_tick.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdint>

//
// === ASSIGNMENT OPERATORS === //
//

SCENARIO("Templated assignment operator assigns integer value") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1;

        WHEN("An integer value is assigned") {
            t1 = 50;

            THEN("The object should store the assigned value") {
                REQUIRE(t1.value() == 50);
            }
        }
    }
}

SCENARIO("Templated assignment operator assigns unsigned value") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1;

        WHEN("An unsigned value is assigned") {
            t1 = 100ULL;

            THEN("The object should store the assigned value") {
                REQUIRE(t1.value() == 100ULL);
            }
        }
    }
}

//
// === INCREMENT OPERATORS === //
//

SCENARIO("Templated addition operator adds different convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It can add int") {
            REQUIRE((t1 + 20).value() == 30);
        }

        THEN("It can add unsigned long long") {
            REQUIRE((t1 + 20ULL).value() == 30);
        }

        THEN("It can add backend_t") {
            ember::sim::backend_t value = 20;
            REQUIRE((t1 + value).value() == 30);
        }
    }
}

SCENARIO("Templated addition assignment operator adds different convertible values") {
    GIVEN("A Tick object") {
        THEN("It can add int") {
            ember::sim::Tick t1(10);
            t1 += 20;
            REQUIRE(t1.value() == 30);
        }

        THEN("It can add unsigned long long") {
            ember::sim::Tick t1(10);
            t1 += 20ULL;
            REQUIRE(t1.value() == 30);
        }

        THEN("It can add backend_t") {
            ember::sim::Tick t1(10);
            ember::sim::backend_t value = 20;
            t1 += value;
            REQUIRE(t1.value() == 30);
        }
    }
}

//
// === DECREMENT OPERATORS === //
//

SCENARIO("Templated subtraction operator subtracts different convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(50);

        THEN("It can subtract int") {
            REQUIRE((t1 - 20).value() == 30);
        }

        THEN("It can subtract unsigned long long") {
            REQUIRE((t1 - 20ULL).value() == 30);
        }

        THEN("It can subtract backend_t") {
            ember::sim::backend_t value = 20;
            REQUIRE((t1 - value).value() == 30);
        }
    }
}

SCENARIO("Templated subtraction assignment operator subtracts different convertible values") {
    GIVEN("A Tick object") {
        THEN("It can subtract int") {
            ember::sim::Tick t1(50);
            t1 -= 20;
            REQUIRE(t1.value() == 30);
        }

        THEN("It can subtract unsigned long long") {
            ember::sim::Tick t1(50);
            t1 -= 20ULL;
            REQUIRE(t1.value() == 30);
        }

        THEN("It can subtract backend_t") {
            ember::sim::Tick t1(50);
            ember::sim::backend_t value = 20;
            t1 -= value;
            REQUIRE(t1.value() == 30);
        }
    }
}

//
// === LOGICAL OPERATORS === //
//

SCENARIO("Templated equality operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is equal to the same integer value") {
            REQUIRE(t1 == 10);
        }

        THEN("It is not equal to a different integer value") {
            REQUIRE_FALSE(t1 == 20);
        }
    }
}

SCENARIO("Templated inequality operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is not equal to a different integer value") {
            REQUIRE(t1 != 20);
        }

        THEN("It is false for the same integer value") {
            REQUIRE_FALSE(t1 != 10);
        }
    }
}

SCENARIO("Templated less-than operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is less than a larger value") {
            REQUIRE(t1 < 20);
        }

        THEN("It is not less than a smaller value") {
            REQUIRE_FALSE(t1 < 5);
        }
    }
}

SCENARIO("Templated less-than-or-equal operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is less than a larger value") {
            REQUIRE(t1 <= 20);
        }

        THEN("It is equal to the same value") {
            REQUIRE(t1 <= 10);
        }

        THEN("It is not less than or equal to a smaller value") {
            REQUIRE_FALSE(t1 <= 5);
        }
    }
}

SCENARIO("Templated greater-than operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is greater than a smaller value") {
            REQUIRE(t1 > 5);
        }

        THEN("It is not greater than a larger value") {
            REQUIRE_FALSE(t1 > 20);
        }
    }
}

SCENARIO("Templated greater-than-or-equal operator compares with convertible values") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        THEN("It is greater than a smaller value") {
            REQUIRE(t1 >= 5);
        }

        THEN("It is equal to the same value") {
            REQUIRE(t1 >= 10);
        }

        THEN("It is not greater than or equal to a larger value") {
            REQUIRE_FALSE(t1 >= 20);
        }
    }
}
