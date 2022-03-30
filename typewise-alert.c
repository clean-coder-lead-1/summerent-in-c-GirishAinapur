#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  int retvalue = 0;
  
  if(value < lowerLimit) 
  {
    retvalue = TOO_LOW;
  }
  else if(value > upperLimit)
  {
    retvalue = TOO_HIGH;
  }
  else
  {
    retvalue = NORMAL;
  }
  return retvalue;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
      int lowerLimit = 0;
      int upperLimit = 0;
      switch(coolingType) 
      {
          case PASSIVE_COOLING:
          {
            lowerLimit = 0;
            upperLimit = 35;
            break;
          }
          case HI_ACTIVE_COOLING:
          {
            lowerLimit = 0;
            upperLimit = 45;
            break;
          }
          case MED_ACTIVE_COOLING:
          {
            lowerLimit = 0;
            upperLimit = 40;
            break;
          }
          default:
          {
            // do nothing
          }
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
      BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  
      alertTarget == TO_CONTROLLER ? sendToController(breachType) : sendToEmail(breachType);
}

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";

  breachType == TOO_LOW ? printf("To: %s\n %s\n", recepient, "Hi, the temperature is too low\n"): printf("To: %s\n %s\n", recepient, "Hi, the temperature is too high\n");
}
