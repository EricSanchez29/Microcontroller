#include "ArduinoByteComm.h"

// Pins 0-12 (nano doesn't have pin 13)
// need to create another constructor for more custom mapping
ArduinoByteComm::ArduinoByteComm(int firstPin, int lastPin)
{
    if (lastPin - firstPin != 7)
    {
        return;
    }

    int j = 0;

    for (int i = firstPin; i <= lastPin; i++)
    {
        //Serial.println(i);
        _pinMap[j] = i;
        j++;
    }

    return;
}

// writes the byte

void ArduinoByteComm::Write(byte data)
{
    //Serial.println();
    //Serial.print("data: ");
    //Serial.print(data, BIN);
    
    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t pin = _pinMap[i];
        pinMode(pin, OUTPUT);
        digitalWrite((int)pin, _getPinData(data, i));
    }
    
   return;
}

// no error handling "cross your fingers"
bool ArduinoByteComm::_getPinData(byte data, uint8_t bit)
{
    data = data>>(7-bit);

    // bit make this bit
    data = data ^ B11111110;

    if (data & B00000001)
    {
        return  true;
    }

    return false;
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
