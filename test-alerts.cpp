#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

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


TEST_CASE("Alert - Controller 3") 
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

