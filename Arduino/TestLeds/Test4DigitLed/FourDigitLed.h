
/*
  Made for a 12 pin, 4 digit LED display
  (NFD-5641AS)
*/

#ifndef FourDigitLedLib
#define FourDigitLedLib
#include "ArduinoComm.h"
#include <Arduino.h>
// Can easily switch <Arduino.h> with the cpp library <cstdint> (has definition for uint8_t but not byte)

/*
      ___     ___     ___    ___
    F| A |B  |   |   |   |  |   |
      ___     ___     ___    ___
    E| G |C  |   |   |   |  |   |
      ___     ___     ___    ___
      D  *H
   
 Digit: 1      2       3      4

Digit data is a byte = ABCDEFGH
  can add dot to any integer 0-9

Digit selection is a half byte:
  1110 for digit 1
  1101 for digit 2
  1011 for digit 3
  1110 for digit 4
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
      B11110110, // 9
      B00000001  // .
};

class FourDigitLed 
{
  public:

    FourDigitLed();

    FourDigitLed(int firstPin, int lastPin);

    void Write(uint16_t number);

    void ClearScreen();

  private:
    // each digit is 1 byte
    uint8_t* convertInt(uint16_t number);

    void selectDigit(uint8_t digit);

    ArduinoComm _comm;
};

#endif
