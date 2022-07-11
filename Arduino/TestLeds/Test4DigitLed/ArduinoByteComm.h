/*
  Made for Arduino (nano or uno) [currently doesn't support pin 13]
  
  8 pin (1-byte) digital read/write
*/

#ifndef ArduinoWrite
#define ArduinoWrite
#include <Arduino.h>


const uint8_t _bitMask[8] = 
{
      B01111111, // A
      B10111111, // B
      B11011111, // C
      B11101111, // D
      B11110111, // E
      B11111011, // F
      B11111101, // G
      B11111110, // H
};

class ArduinoByteComm
{
  public:
    // currently only supports sequential pins
    // board is connected from firstPin throught lastPin
    // where the first pin, it the most significant bit in the byte
    ArduinoByteComm(uint8_t firstPin, uint8_t lastPin);
    
    void Write(byte data);

    byte Read();

  private:
    uint8_t _pinMap[8];
    
    // byte is formatted like ABCDEFGH, will call the leftmost digit 0
    
    bool _getPinData(byte data, uint8_t bit);
};

#endif
