#include "FourDigitLed.h"
#include "ArduinoCommByte.h"
#include "ArduinoCommNybl.h"

// Need default constructor 
FourDigitLed::FourDigitLed() {}

// the default usage of this should be (0, 11)
// this is because I need at least 12 bits (nano only has 13 digital lines including tx/rx)
FourDigitLed::FourDigitLed(int firstNumber, int lastNumber)
{
    // first 4 bits are used to choose digit
    _digitSelect = ArduinoCommNybl::ArduinoCommNybl(firstNumber, firstNumber + 3);

    // the last 8 bits are the data correspoding to LED segments
    _digitData = ArduinoCommByte::ArduinoCommByte(firstNumber + 4, lastNumber);
}

void FourDigitLed::Write(uint16_t number)
{
    int8_t *data;
    // can I do this in one line?
    data = convertInt(number);

    for (int16_t countDown = 50; countDown > 0; countDown--)
    {
        // since each digit in the LED screen
        // shares data lines, need to switch between them quickly
        for (int8_t i = 0; i < 4; i++)
        {
            selectDigit(i+1);
            _digitData.WriteByte(data[i]);
            delay(5);
            ClearSceen();
        }
    }
}

// 1, 2, 3, 4
// 1 pin LOW, rest of pins HIGH -> 1 pin selected
void FourDigitLed::selectDigit(uint8_t digit)
{
    // can I use a half byte data type instead?
    switch(digit) 
    {
        case 1 :
        _digitSelect.WriteNybl(B00000111);
        return;

        case 2 :
        _digitSelect.WriteNybl(B00001011);
        return;

        case 3 :
        _digitSelect.WriteNybl(B00001101);
        return;

        case 4 :
        _digitSelect.WriteNybl(B00001110);
        return;

        default:
        return;
    }
}

// All digit select lines are HIGH
void static FourDigitLed::ClearScreen()
{
    // alternatively all zeros, is this dangerous for the circuit? (no ground if all data pins are 1)
    _digitSelect.WriteNybl(1111);
    _digitData.WriteByte(B00000000);
}

uint8_t* FourDigitLed::convertInt(uint16_t number)
{
    uint8_t static someArray[4];

    // no need to check negative
    // this code will never be excercised using uint8_t (max number is 256)
    if (number > 9999)
    {
        for (int i = 0; i <= 3; i++)
        {
            someArray[i] = _segmentCodes[10];
        }
    }
    else
    {
        uint16_t divisor = 1000;
        uint16_t quotient = 0;

        for (int i = 0; i < 4; i++)
        {
            if(number >= divisor)
            {
                quotient = number / divisor;

                someArray[i] = _segmentCodes[quotient];

                number = number - (quotient * divisor);
            }
            // if there is nothing left to divide make the rest of the segments 0
            else if(number == 0)
            {
                someArray[i] = _segmentCodes[0];
            }
            else
            {
                someArray[i] = B00000000;
            }

            divisor = divisor / 10;
        }
    }

    return someArray;
}
