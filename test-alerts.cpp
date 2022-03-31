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


TEST_CASE("Alert - Controller 1") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = PASSIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, -10);
}

TEST_CASE("Alert - Controller 2") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = (CoolingType)4;
  BatChar.brand[48] = {0};
  
  checkAndAlert((AlertTarget)5, BatChar, 10);
}

TEST_CASE("Alert - Controller 3") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = PASSIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, -5);
}

TEST_CASE("Alert - Controller 4") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = PASSIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, 50);
}


TEST_CASE("Alert - Controller 5") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = PASSIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, 0);
}

TEST_CASE("Alert - Email 1") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = MED_ACTIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_EMAIL, BatChar, 30);
}

TEST_CASE("Alert - Email 2") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = MED_ACTIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_EMAIL, BatChar, 30);
}

TEST_CASE("Alert - Email 3") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = HI_ACTIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_EMAIL, BatChar, 50);
}

