#include "ArduinoComm.h"
#include "FourDigitLed.h"

void setup() 
{
  // Set all digital pins as output:
  for (int i = 0; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

  FourDigitLed led = FourDigitLed::FourDigitLed(0, 11);

  // largest number I can represent
  led.Write(9999);

  // this number is too big to display with 4 digits
  // prints 4 periods '.'
  led.Write(10000);

  led.Write(1234);

  led.ClearScreen();
}

void loop() 
{ 
}
