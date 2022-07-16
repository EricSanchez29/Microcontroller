#include "ArduinoComm.h"
#include "FourDigitLed.h"

void setup() 
{
  FourDigitLed led = FourDigitLed::FourDigitLed(0, 11);

  // largest number I can represent
  //led.Write(9999);

  // this number is too big to display with 4 digits
  // prints 4 periods '.'
  //led.Write(10000);

  //led.Write(1234);

  //led.Write(888);

  led.Write(11111);

  led.Write((uint16_t)1);
  led.Write((uint16_t)0010);
  led.Write((uint16_t)0100);
  led.Write((uint16_t)1001);

  led.ClearScreen();
}

void loop() 
{ 
  
}
