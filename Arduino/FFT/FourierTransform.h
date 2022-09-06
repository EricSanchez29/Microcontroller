#pragma once

#define _USE_MATH_DEFINES
#include "Arduino.h";
//#include <cstdint>;
//#include <cmath>;

class FourierTransform
{
    public:
        static int32_t* DFT(uint16_t* inputArray);
        static uint8_t GetPeakFrequency(int32_t* freqArray);
};
