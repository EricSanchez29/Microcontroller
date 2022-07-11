#include "ArduinoByteComm.h"

// Pins 0-12 (nano doesn't have pin 13)
// need to create another constructor for more custom mapping
ArduinoByteComm::ArduinoByteComm(uint8_t firstPin, uint8_t lastPin)
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

// writes the byte

void ArduinoByteComm::Write(byte data)
{
    for (int i = 0; i < 8; i++)
    {
        uint8_t pin = _pinMap[i];

        bool pinData = _getPinData(data, i);

        pinMode(pin, OUTPUT);
        digitalWrite(pin, pinData);
    }
    
   return;
}

// no error handling "cross your fingers"
bool ArduinoByteComm::_getPinData(byte data, uint8_t bit)
{
    byte filtered = data ^ _bitMask[bit];

    return filtered>>(7-bit);
}


byte ArduinoByteComm::Read()
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
