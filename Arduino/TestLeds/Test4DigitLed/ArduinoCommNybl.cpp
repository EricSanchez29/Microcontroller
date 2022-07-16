#include "ArduinoCommNybl.h"

// Need default constructor 
ArduinoCommNybl::ArduinoCommNybl(){}

// Pins 0-12 (Arduino Nano doesn't have pin 13 or 14, so I'm using the tx/rx pins (1 & 0))
// Create another constructor for more custom mapping?
ArduinoCommNybl::ArduinoCommNybl(int firstPin, int lastPin)
{
    if (lastPin - firstPin != 3)
    {
        // should add exception or something here since these are not proper inputs
        return;
    }

    int j = 0;

    for (int i = firstPin; i <= lastPin; i++)
    {
        _pinMap[j] = i;
        j++;
    }

    return;
}

// Read the first 4 bits of byte
// ex. Bxxxx0101
void ArduinoCommNybl::WriteNybl(byte data)
{    
    for (uint8_t i = 0; i < 4; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, OUTPUT);
        digitalWrite((int)pin, _getPinData(data, i));
    }
    
   return;
}

bool ArduinoCommNybl::_getPinData(byte data, uint8_t bit)
{
    data = data>>(3-bit);

    data = data ^ B11111110;

    if (data & B00000001)
    {
        return  true;
    }

    return false;
}

// need to test this
byte ArduinoCommNybl::ReadNybl()
{
    byte result;

    for (int i = 0; i < 4; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, INPUT);
        result = result && digitalRead(pin);
        result<<1;
    }
    
   return result;
}