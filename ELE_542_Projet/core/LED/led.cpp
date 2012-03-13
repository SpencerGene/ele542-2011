/************************************************************************/
/*  Title       : led.cpp                                               */
/*                                                                      */
/*  Class       : ELE-542                                               */  
/*                                                                      */
/*  Written by  : Joel Bourbonnais & Olivier Mass�                      */
/*	                                                                    */
/*  Summary     :        */
/*                                                                      */
/************************************************************************/
#include "led.h"
#include "singleton.h"

led::led(volatile uint8_t *iPORTX, volatile uint8_t *iDDRX, uint8_t iPinNumber, LedType iType):
    pin(iPORTX, iDDRX, iPinNumber, PinOutput)
  , Type(iType)
  , Active(0)
{
}

led::led() : pin()
{   }

void led::ON()
{
	clearPIN();
}

void led::OFF()
{
	setPIN();
}

void led::activateLED()
{
	Active = 1;
	ON();
	
	if(Type == Instance)
		NextEventTime = s.Timer1.time_ms + (INSTANCEDELAY * 1000);
}

void led::deactivateLED()
{
	Active = 0;
	OFF();	
}