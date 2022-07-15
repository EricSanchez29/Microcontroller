/*
  Made for Arduino (nano or uno) [currently doesn't support pin 13]
  8 pin (1-byte) digital read/write
*/

#ifndef ArduinoWrite
#define ArduinoWrite
#include <Arduino.h>


class ArduinoComm
{
  public:
    // currently only supports sequential pins
    // board is connected from firstPin throught lastPin
    // where the first pin, it the most significant bit in the byte

    ArduinoComm();

    ArduinoComm(int firstPin, int lastPin);
    
    void Write(byte data);

    byte Read();

  private:
    uint8_t _pinMap[8];
    
    // byte is formatted like ABCDEFGH, will call the leftmost digit 0
    // byte and uint8_t are technically equivalent
    bool _getPinData(byte data, uint8_t bit);
};

#endif
