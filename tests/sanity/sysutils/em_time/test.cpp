#include "ember/sysutils/em_time.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <sstream>

//
// === Tick MEMBERS === //
//

SCENARIO("Set() function handles self assignment") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(42);

        WHEN("The object is set using itself") {
            t1.set(t1);

            THEN("The value should remain unchanged") {
                REQUIRE(t1.value() == 42);
            }
        }
    }
}

SCENARIO("value() return the stored time") {
    GIVEN("a time object with backend_t type value") {
        const ember::sim::Tick t(25);

        WHEN("value() is called") {
            THEN("it will pass") {
                REQUIRE(t.value() == (25));
            }
        }
    }
}

SCENARIO("value() returns the stored time (min edge case)") {
    GIVEN("a time object with min backend_t type  value") {
        const ember::sim::Tick t(0);

        WHEN("value() is called") {
            THEN("it should return the same backend_t type value") {
                REQUIRE(t.value() == 0);
            }
        }
    }
}

SCENARIO("value() returns the stored time (Max edge case) ") {
    GIVEN("a time object with max backend_t type value") {
        const ember::sim::Tick t(UINT64_MAX);

        WHEN("value() is called") {
            THEN("it should return the same backend_t type value") {
                REQUIRE(t.value() == UINT64_MAX);
            }
        }
    }
}

SCENARIO("Set() copies value from another Tick object") {
    GIVEN("Two Tick objects with different values") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(50);

        WHEN("t1 is set using t2") {
            t1.set(t2);

            THEN("t1 should have the same value as t2") {
                REQUIRE(t1.value() == t2.value());
            }
        }
    }
}

SCENARIO("Reset function sets time value to zero") {
    GIVEN("A Tick object with a non-zero value") {
        ember::sim::Tick t1(50);

        WHEN("reset is called") {
            t1.reset();

            THEN("The time value should become zero") {
                REQUIRE(t1.value() == 0);
            }
        }
    }
}

SCENARIO("Increment increases time by one") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        WHEN("incr() is called") {
            t1.incr();

            THEN("Time value should increase by one") {
                REQUIRE(t1.value() == 11);
            }
        }
    }
}

//
// === ASSIGNMENT OPERATORS === //
//

SCENARIO("Assignment operator copies value from another object") {
    GIVEN("Two Tick objects with different values") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(250);

        WHEN("t1 is assigned using t2") {
            t1 = t2;

            THEN("t1 should have the same value as t2") {
                REQUIRE(t1.value() == t2.value());
            }
        }
    }
}

SCENARIO("Assignment operator handles self assignment") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(12);

        WHEN("The object is assigned to itself") {
            t1 = t1;

            THEN("The value should remain unchanged") {
                REQUIRE(t1.value() == 12);
            }
        }
    }
}

//
// === INCREMENT OPERATORS === //
//

SCENARIO("Addition operator returns the sum of two Tick objects") {
    GIVEN("Two Tick objects") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(20);

        WHEN("The addition operator is used") {
            ember::sim::Tick result = t1 + t2;

            THEN("The returned object should contain the summed value") {
                REQUIRE(result.value() == 30);
            }
        }
    }
}

SCENARIO("Prefix increment increases the value by one") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        WHEN("Prefix increment operator is applied") {
            ++t1;

            THEN("The value should increase by one") {
                REQUIRE(t1.value() == 11);
            }
        }
    }
}

SCENARIO("Postfix increment increases the value by one") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        WHEN("Postfix increment is applied") {
            t1++;

            THEN("The value should increase by one") {
                REQUIRE(t1.value() == 11);
            }
        }
    }
}

SCENARIO("Addition assignment operator adds value to current object") {
    GIVEN("Two Tick objects") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(20);

        WHEN("Addition assignment operator is used") {
            t1 += t2;

            THEN("The current object should contain the summed value") {
                REQUIRE(t1.value() == 30);
            }
        }
    }
}

//
// === DECREMENT OPERATORS === //
//

SCENARIO("Subtraction operator returns the difference of two Tick objects") {
    GIVEN("Two Tick objects") {
        ember::sim::Tick t1(50);
        ember::sim::Tick t2(20);

        WHEN("The subtraction operator is used") {
            ember::sim::Tick result = t1 - t2;

            THEN("The returned object should contain the difference") {
                REQUIRE(result.value() == 30);
            }
        }
    }
}

SCENARIO("Prefix decrement decreases the value by one") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        WHEN("Prefix decrement is applied") {
            --t1;

            THEN("The value should decrease by one") {
                REQUIRE(t1.value() == 9);
            }
        }
    }
}

SCENARIO("Postfix decrement decreases the value by one") {
    GIVEN("A Tick object") {
        ember::sim::Tick t1(10);

        WHEN("Postfix decrement is applied") {
            t1--;

            THEN("The value should decrease by one") {
                REQUIRE(t1.value() == 9);
            }
        }
    }
}

SCENARIO("Subtraction assignment operator subtracts value from current object") {
    GIVEN("Two Tick objects") {
        ember::sim::Tick t1(50);
        ember::sim::Tick t2(20);

        WHEN("Subtraction assignment operator is used") {
            t1 -= t2;

            THEN("The current object should contain the difference") {
                REQUIRE(t1.value() == 30);
            }
        }
    }
}

//
// === LOGICAL OPERATORS === //
//

SCENARIO("Equality operator compares two Tick objects") {
    GIVEN("Two Tick objects with the same value") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(10);

        THEN("They should be equal") {
            REQUIRE(t1 == t2);
        }
    }
}

SCENARIO("Inequality operator compares two Tick objects") {
    GIVEN("Two Tick objects with different values") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(20);

        THEN("They should not be equal") {
            REQUIRE(t1 != t2);
        }
    }
}

SCENARIO("Less-than operator compares two Tick objects") {
    GIVEN("One Tick object has a smaller value") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(20);

        THEN("The smaller object should be less than the larger object") {
            REQUIRE(t1 < t2);
        }
    }
}

SCENARIO("Less-than-or-equal operator compares two Tick objects") {
    GIVEN("Two Tick objects with the same value") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(10);

        THEN("The first object should be less than or equal to the second object") {
            REQUIRE(t1 <= t2);
        }
    }
}

SCENARIO("Greater-than operator compares two Tick objects") {
    GIVEN("One Tick object has a larger value") {
        ember::sim::Tick t1(20);
        ember::sim::Tick t2(10);

        THEN("The larger object should be greater than the smaller object") {
            REQUIRE(t1 > t2);
        }
    }
}

SCENARIO("Greater-than-or-equal operator compares two Tick objects") {
    GIVEN("Two Tick objects with the same value") {
        ember::sim::Tick t1(10);
        ember::sim::Tick t2(10);

        THEN("The first object should be greater than or equal to the second object") {
            REQUIRE(t1 >= t2);
        }
    }
}

//
// === CTOR === //
//

SCENARIO("Default constructor initializes time to zero") {
    GIVEN("A default constructed Tick object") {
        ember::sim::Tick t1;

        THEN("The time value should be zero") {
            REQUIRE(t1.value() == 0);
        }
    }
}

SCENARIO("Parameterized constructor initializes time value") {
    GIVEN("A time value") {
        ember::sim::Tick t1(50);

        THEN("The object should store the given time value") {
            REQUIRE(t1.value() == 50);
        }
    }
}

SCENARIO("Constructor with time and unit initializes time value") {
    GIVEN("A time value and a unit") {
        ember::sim::Tick t1(50, "clk(s)");

        THEN("The object should store the given time value") {
            REQUIRE(t1.value() == 50);
        }
    }
}

SCENARIO("Copy constructor copies time value from another object") {
    GIVEN("An existing Tick object") {
        ember::sim::Tick t1(75);

        WHEN("A new object is created from the existing object") {
            ember::sim::Tick t2(t1);

            THEN("The new object should have the same time value") {
                REQUIRE(t2.value() == t1.value());
            }
        }
    }
}

SCENARIO("Tick stream operator prints correct output", "[tick][ostream]") {
    GIVEN("A Tick object with a valid value") {
        ember::sim::Tick tick(10);
        std::stringstream ss;

        WHEN("The Tick object is streamed into an ostream") {
            ss << tick;

            THEN("The correct formatted string is written") {
                REQUIRE(ss.str() == "10 " + std::string(ember::sim::U_TIME));
            }
        }
    }
}