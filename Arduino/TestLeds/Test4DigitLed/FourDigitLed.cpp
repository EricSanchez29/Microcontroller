#include "FourDigitLed.h"

// All pins LOW -> all pins selected
byte ConvertToFourDigitLed::SelectAllDigits()
{
   return 00000000;
}

// 1 pin LOW, rest of pins HIGH -> 1 pin selected
byte ConvertToFourDigitLed::SelectDigit(byte dig)
{
    // can I use a half byte data type instead?
    switch(dig) 
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
byte static ConvertToFourDigitLed::Clean()
{
    return 00000000;
}

char32_t static ConvertToFourDigitLed::ConvertInt(uint8_t number)
{
    char32_t result =  0;

    uint8_t array[4];

    // no need to check negative
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

        uint8_t dec = number % multiplier;

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

    // Convert to uint32 (4 bytes)
    for (int i = 0; i < 3; i++)
    {
        result = result + array[i];
        
        result<<4;
    }

    result = result + array[3];

    return result;
}

char32_t ConvertToFourDigitLed::ConvertFloat(float number)
{
    return 0;
}
