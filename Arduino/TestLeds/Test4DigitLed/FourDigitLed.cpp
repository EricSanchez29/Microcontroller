#include "FourDigitLed.h"
#include "ArduinoByteComm.h"  

FourDigitLed::FourDigitLed(int firstNumber, int lastNumber)
{

    // figure out how to do half byte comm?

    digitalWrite(0, true);
    digitalWrite(1, true);
    digitalWrite(2, true);
    digitalWrite(3, false);

    //_comm = ArduinoByteComm::ArduinoByteComm();
    _comm = ArduinoByteComm::ArduinoByteComm(4, 11);
}

void FourDigitLed::Write(uint16_t number)
{
    

    _comm.Write()
    _comm.Write()
    _comm.Write()
    _comm.Write()
}

// All pins LOW -> all pins selected
byte FourDigitLed::selectAllDigits()
{
   return 00000000;
}

// 1 pin LOW, rest of pins HIGH -> 1 pin selected
byte FourDigitLed::selectDigit(uint8_t digit)
{
    // can I use a half byte data type instead?
    switch(digit) 
    {
        case 1 :
        return B00001110;

        case 2 :
        return B00001101;

        case 3 :
        return B00001011;

        case 4 :
        return B00000111;

        default :
        return B00001111;
    }
}

// All segments LOW
byte static FourDigitLed::Clean()
{
    return 00000000;
}

char32_t FourDigitLed::convertInt(uint16_t number)
{
    char32_t result =  0;

    uint8_t array[4];

    // no need to check negative
    // this code will never be excercised using uint8_t (max number is 256)
    if (number > 9999)
    {
        for (int i = 0; i < 3; i++)
        {
            array[i] = _segmentCodes[0];
        }
    }
    else
    {
        int multiplier = 1000;

        uint16_t dec = number % multiplier;

        for (int i = 0; i < 4; i++)
        {
            array[i] = _segmentCodes[dec];
            number = number - (dec * multiplier);
            multiplier = multiplier / 10;
        }

        if (number != 0)
        {
            // ?
            //throw "";
        }
    }

    // Convert to char32_t (4 bytes)
    for (int i = 0; i < 3; i++)
    {
        result = result + array[i];
        
        result<<4;
    }

    result = result + array[3];

    return result;
}

char32_t FourDigitLed::convertFloat(float number)
{
    return 0;
}
