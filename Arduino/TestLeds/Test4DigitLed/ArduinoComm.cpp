#include "ArduinoComm.h"  

// Need default constructor 
ArduinoComm::ArduinoComm(){}

// Pins 0-12 (Arduino Nano doesn't have pin 13 or 14, so I'm using the tx/rx lines)
// Create another constructor for more custom mapping?
ArduinoComm::ArduinoComm(int firstPin, int lastPin)
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

void ArduinoComm::Write(byte data)
{    
    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, OUTPUT);
        digitalWrite((int)pin, _getPinData(data, i));
    }
    
   return;
}

bool ArduinoComm::_getPinData(byte data, uint8_t bit)
{
    data = data>>(7-bit);

    data = data ^ B11111110;

    if (data & B00000001)
    {
        return  true;
    }

    return false;
}

byte ArduinoComm::Read()
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
