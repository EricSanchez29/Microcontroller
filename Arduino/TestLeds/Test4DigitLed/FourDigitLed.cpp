#include "FourDigitLed.h"
#include "ArduinoComm.h"

// Need default constructor 
FourDigitLed::FourDigitLed() {}

// the default usage of this should be (0, 11)
// this is because I need at least 12 bits (nano only has 13 digital lines including tx/rx)
FourDigitLed::FourDigitLed(int firstNumber, int lastNumber)
{
    // no digit selected
    for (int i = 0; i < 4; i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, true);
    }

    // first 4 numbers are used to choose digit place
    _comm = ArduinoComm::ArduinoComm(firstNumber + 4, lastNumber);
}

void FourDigitLed::Write(uint16_t number)
{
    int8_t *data;
    
    data = convertInt(number);

    for (int16_t countDown = 400; countDown > 0; countDown--)
    {
        // since each digit in the of the LED screen
        // shares data lines, need to switch between them quickly
        for (int8_t i = 0; i < 4; i++)
        {
            selectDigit(i+1);
            
            _comm.Write(data[i]);
            delay(3);
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
        // could make this neater if I create a half byte class for communicating with pins 0-3
        digitalWrite(0, false);
        digitalWrite(1, true);
        digitalWrite(2, true);
        digitalWrite(3, true);
        return;

        case 2 :

        digitalWrite(0, true);
        digitalWrite(1, false);
        digitalWrite(2, true);
        digitalWrite(3, true);
        return;

        case 3 :

        digitalWrite(0, true);
        digitalWrite(1, true);
        digitalWrite(2, false);
        digitalWrite(3, true);
        return;

        case 4 :

        digitalWrite(0, true);
        digitalWrite(1, true);
        digitalWrite(2, true);
        digitalWrite(3, false);
        return;

        default :
        return;
    }
}

// All digit select lines are HIGH
void static FourDigitLed::ClearScreen()
{
    for (int i = 0; i < 4; i++)
    {
        // alternatively I could set these to false
        digitalWrite(i, true);
    }
        
    // Is this redundant?
    // This does ensure that all byte lines are LOW 
    // before exiting this function;
    _comm.Write(B00000000);

    
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
            if(number > divisor)
            {
                quotient = number / divisor;

                someArray[i] = _segmentCodes[quotient];

                number = number - (quotient * divisor);
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
