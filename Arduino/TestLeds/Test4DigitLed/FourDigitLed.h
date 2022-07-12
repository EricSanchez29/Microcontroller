
/*
  Made for a 12 pin, 4 LED display
  NFD-5641AS
 
  Adapted from a libary which uses //#include <Arduino.h>

  I don't want to have a dependency on arduino here, is there any conversion I need to do
  in the .ino file?

*/

#ifndef FourDigitLedLib
#define FourDigitLedLib
#include "ArduinoByteComm.h"
#include <Arduino.h>
// Can easily switch <Arduino.h> with the cpp library <cstdint> (has definition for uint8_t but not byte)
// I am using the Arduino library here for the datatypes 'uint8_t' and 'byte' 
//  which are equivalent but are used in order to provide clarity


/*

4 digit LED segments
  ___     ___
F| A |B  |   |
  ___     ___
E| G |C  |   |
  ___     ___   ...
   D  *H
   
 Digit 1 Digit 2 Digit 3 Digit 4

Digit data is a byte = ABCDEFGH
  can add dot to any digit 0-9


Digit selection is a half byte:
  1110 for digit 1
  1101 for digit 2
*/
const uint8_t _segmentCodes[] = 
{
      B11111100, // 0
      B01100000, // 1
      B11011010, // 2
      B11110010, // 3
      B01100110, // 4
      B10110110, // 5
      B10111110, // 6
      B11100000, // 7
      B11111110, // 8
      B11110110  // 9
};

class FourDigitLed 
{
  public:

    FourDigitLed(int firstPin, int lastPin);

    void Write(uint16_t number);

    byte Clean();

  private:
    // each digit is 1 byte, char32_t is 4 bytes
    char32_t convertInt(uint16_t number);
    char32_t convertFloat(float number);
    byte selectAllDigits();
    byte selectDigit(uint8_t digit);
    ArduinoByteComm _comm;
};

#endif
