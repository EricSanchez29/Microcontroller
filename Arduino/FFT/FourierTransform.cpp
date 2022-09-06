#include "FourierTransform.h"

int32_t* FourierTransform::DFT(uint16_t* inputArray)
{
	uint32_t static real_result[128];

	// might delete later
	// will just use to compare with FFT
	//int16_t imag_result[128];

	for (uint16_t k = 0; k < 128; k++)
	{
		float real_value = 0;

		//float imag_value = 0;

		for (uint16_t m = 0; m < 128; m++)
		{
			real_value = real_value + inputArray[m] * cos((2 * M_PI * m * k) / 128);
			//imag_value = imag_value + inputArray[m] * sin((2 * Pi * m * k) / 256);
		}

		real_result[k] = round(real_value);
		//imag_result[k] = round(imag_value);
	}

	return real_result;
}


uint8_t FourierTransform::GetPeakFrequency(int32_t* freqSpace)
{
	// gives frequency, relative to orignal sample rate in time space
	// aka the index of the freqArray
	uint8_t peakFreq = 0;

	// finds the first peak frequency, might discover multiple peaks in the process, 
	// return the smaller frequency (larger ones are possible overtones)
	long peakValue = freqSpace[0];

	// find largest value starting from index 0, ignore subsequent equivalent values (repeat peaks)
	for (uint16_t i = 1; i < 128; i++)
	{
		long currentValue = abs(freqSpace[i]);

		if (peakValue < currentValue)
		{
			peakValue = currentValue;
			peakFreq = i;
		}
	}

	return peakFreq;
}
