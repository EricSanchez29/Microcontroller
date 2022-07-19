/*
  Made for Arduino (nano or uno) [currently doesn't support pin 13]
  8 pin (1-byte) digital read/write
*/

#include <Arduino.h>
#ifndef ArduinoByte
#define ArduinoByte
class ArduinoCommByte
{
  public:
    // currently only supports sequential pins
    // board is connected from firstPin throught lastPin
    // where the first pin, it the most significant bit in the byte

    ArduinoCommByte();

    ArduinoCommByte(int firstPin, int lastPin);

    //B:ABCDEFGH
    void WriteByte(byte data);

    byte ReadByte();

  private:
    uint8_t _pinMap[8];
    
    // byte is formatted like ABCDEFGH, will call the leftmost digit 0
    // byte and uint8_t are technically equivalent
    bool _getPinData(byte data, uint8_t bit);
};
#endif
