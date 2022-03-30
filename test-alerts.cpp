#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits - Normal") 
{
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("infers the breach according to limits - Low") 
{
  REQUIRE(inferBreach(-10, 0, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits - High") 
{
  REQUIRE(inferBreach(50, 10, 30) == TOO_HIGH);
}
