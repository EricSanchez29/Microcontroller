  /*
  Made for Arduino (nano or uno) [currently doesn't support pin 13]
  4 pin (half-byte) digital read/write
*/

#include <Arduino.h>
#ifndef ArduinoNybl
#define ArduinoNybl
class ArduinoCommNybl
{
  public:
    // currently only supports sequential pins
    // board is connected from firstPin throught lastPin
    // where the first pin, it the most significant bit in the half-byte

    ArduinoCommNybl();

    ArduinoCommNybl(int firstPin, int lastPin);

    //B:xxxxB0B1B2B3
    void WriteNybl(byte data);

    byte ReadNybl();

  private:
    uint8_t _pinMap[4];
    
    // byte is formatted like ABCDEFGH, will call the leftmost digit 0
    // byte and uint8_t are technically equivalent
    bool _getPinData(byte data, uint8_t bit);
};
#endif