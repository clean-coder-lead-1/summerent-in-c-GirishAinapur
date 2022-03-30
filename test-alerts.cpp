#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("Alert - Controller") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = PASSIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, -10);
}


TEST_CASE("Alert - Controller") 
{
  BatteryCharacter BatChar;
  
  BatChar.coolingType = MED_ACTIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_CONTROLLER, BatChar, 10);
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
  
  BatChar.coolingType = HI_ACTIVE_COOLING;
  BatChar.brand[48] = {0};
  
  checkAndAlert(TO_EMAIL, BatChar, 50);
}

