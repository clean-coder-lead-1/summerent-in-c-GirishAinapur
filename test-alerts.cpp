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

TEST_CASE("Colling Type Normal") 
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("Colling Type Low") 
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Colling Type High") 
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}

TEST_CASE("Passive Cooling")
{
    BatteryCharacter BattChar;
  
    BattChar.coolingType = PASSIVE_COOLING;
  
    checkAndAlert(TO_EMAIL, BattChar, 45);
    checkAndAlert(TO_EMAIL, BattChar, -10);
    checkAndAlert(TO_EMAIL, BattChar, 25);
  
    checkAndAlert(TO_CONTROLLER, BattChar, 25);
    checkAndAlert(TO_CONTROLLER, BattChar, -5);
    checkAndAlert(TO_CONTROLLER, BattChar, 45);
}

TEST_CASE("Active Cooling")
{
    BatteryCharacter BattChar;
  
    BattChar.coolingType = HI_ACTIVE_COOLING;
  
    checkAndAlert(TO_CONTROLLER, BattChar, 29);
    checkAndAlert(TO_CONTROLLER, BattChar, -7);
    checkAndAlert(TO_CONTROLLER, BattChar, 52);
    
    checkAndAlert(TO_EMAIL, BattChar, 51);
    checkAndAlert(TO_EMAIL, BattChar, -8);
    checkAndAlert(TO_EMAIL, BattChar, 25);
}

TEST_CASE("Medium Active Cooling")
{
    BatteryCharacter BattChar;
  
    BattChar.coolingType = MED_ACTIVE_COOLING;
  
    checkAndAlert(TO_EMAIL, BattChar, 50);
    checkAndAlert(TO_EMAIL, BattChar, -9);
    checkAndAlert(TO_EMAIL, BattChar, 25);
  
    checkAndAlert(TO_CONTROLLER, BattChar, 27);
    checkAndAlert(TO_CONTROLLER, BattChar, -3);
    checkAndAlert(TO_CONTROLLER, BattChar, 55);
    
    
}

