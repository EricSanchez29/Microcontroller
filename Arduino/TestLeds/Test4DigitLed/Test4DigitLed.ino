#include "ArduinoComm.h"
#include "FourDigitLed.h"

/*
 * // Instead of mapping wires here, just connect them so the ports line up where the segement lines are treated as a byte
 *                                                                                and the control lines are treated as half a byte
              // segment name:  a, b, c, d, e,  f, g, dot
const int digitSegmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3};

       // digits left to right:  1, 2, 3, 4
const int digitSelectPins[] = { 12, 9, 8, 6};
// since common cathodes,
// digits are selected by low state
*/

//unsigned long previousMillis = 0;        // will store last time LED was updated

//const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() 
{
  // Set all digital pins as output:
  for (int i = 0; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

  FourDigitLed led = FourDigitLed::FourDigitLed(0, 11);

  led.Write(9999);

  led.Write(10000);

  led.Write(2857);

  led.ClearScreen();
}

void loop() 
{ 
}
