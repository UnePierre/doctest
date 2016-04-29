//#define DOCTEST_CONFIG_DISABLE

#include "doctest.h"

#include <cstdio>

#include <exception>
#include <string>

namespace doctest
{
    template <>
    String stringify(const std::string& in) {
        return String("\"") + in.c_str() + "\"";
    }
} // namespace doctest

TESTSUITE("MAIN");
TESTCASE("zzz") {
    CHECK(std::string("OMG2") == std::string("OMG"));


    //REQUIRE(true == false);
    //
    //printf("main\n");
    //SUBCASE("") {
    //    printf("1\n");
    //    SUBCASE("") { printf("1-1\n"); }
    //    SUBCASE("") { printf("1-2\n"); }
    //}
    //SUBCASE("") { printf("2\n"); }
}
TESTSUITE_END;

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic ignored "-Weffc++"
#endif

struct Empty
{};

TESTCASE_FIXTURE(Empty, "trololo") { printf("Help?\n"); }

// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }
// test("") { printf("TEST %d\n", __LINE__); }

// to silence GCC "-Wmissing-declarations"
// and the attribute is to silence "-Wmissing-noreturn" on clang
#ifdef __clang__
void throws() __attribute__((noreturn));
#else
void throws();
#endif

void throws() { throw std::exception(); }
void nothrows(); // to silence GCC "-Wmissing-declarations"
void nothrows() {}

TESTCASE("zzz") {

    int a = 5;
    int b = 5;
    CHECK(&a == &b);

    CHECK(1 == 1);
    REQUIRE(1 == 1);

    CHECK_FALSE(0);
    REQUIRE_FALSE(0);

    CHECK_THROWS(throws());
    REQUIRE_THROWS(throws());

    CHECK_THROWS_AS(throws(), std::exception);
    REQUIRE_THROWS_AS(throws(), std::exception);

    CHECK_NOTHROW(nothrows());
    REQUIRE_NOTHROW(nothrows());
}
