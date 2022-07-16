#include "ArduinoCommByte.h"  

// Need default constructor 
ArduinoCommByte::ArduinoCommByte(){}

// Pins 0-12 (Arduino Nano doesn't have pin 13 or 14, so I'm using the tx/rx pins (1 & 0))
// Create another constructor for more custom mapping?
ArduinoCommByte::ArduinoCommByte(int firstPin, int lastPin)
{
    if (lastPin - firstPin != 7)
    {
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

void ArduinoCommByte::WriteByte(byte data)
{    
    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, OUTPUT);
        digitalWrite((int)pin, _getPinData(data, i));
    }
    
   return;
}

bool ArduinoCommByte::_getPinData(byte data, uint8_t bit)
{
    data = data>>(7-bit);

    data = data ^ B11111110;

    if (data & B00000001)
    {
        return  true;
    }

    return false;
}

// need to test this
byte ArduinoCommByte::ReadByte()
{
    byte result;

    for (int i = 0; i < 8; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, INPUT);
        result = result && digitalRead(pin);
        result<<1;
    }
    
   return result;
}