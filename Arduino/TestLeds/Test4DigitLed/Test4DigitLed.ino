#include "ArduinoCommByte.h"
#include "ArduinoCommNybl.h"
#include "FourDigitLed.h"

void setup() 
{
  FourDigitLed led = FourDigitLed::FourDigitLed(0, 11);
  // this number is too big to display with 4 digits
  // prints 4 periods '.'
  led.Write(10000);

  // testing different combinations
  // currently see "ghost" image of the adjacent digit (from the left, wraps around)
  // not clearing lines? I am explcitly clearing before switching between digits in Write()
  // does this have to do with the internal hardware of the LEDs?
  //led.Write(8);
  //led.Write(88);
  //led.Write(808);
  //led.Write(8008);
  led.Write(1234);
  led.Write(2345);
  led.Write(3456);
  led.Write(4567);
}

void loop() 
{ 
  
}
