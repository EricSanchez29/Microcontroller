#pragma once
//#include <cstdint>
#include <Arduino.h>

class FourierTransform
{
    public:
        static int16_t* GetFFT(uint16_t* inputArray);
        static int16_t* GetDFT(uint16_t* inputArray);
        static uint8_t GetPeakFrequency(int16_t* freqArray);
};
