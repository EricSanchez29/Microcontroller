#include "FourierTransform.h"

//#include <cmath>;

double Pi = 3.141592653589793;

int16_t* FourierTransform::GetDFT(uint16_t* inputArray)
{
	int16_t static real_result[128];

	// might delete later
	// will just use to compare with FFT
	int16_t imag_result[128];

	for (uint8_t k = 0; k < 128; k++)
	{
		float real_value = 0;

		float imag_value = 0;

		for (uint8_t m = 0; m < 128; m++)
		{
			real_value = real_value + inputArray[m] * cos((2 * Pi * m * k) / 128);
			imag_value = imag_value + inputArray[m] * sin((2 * Pi * m * k) / 128);
		}

		real_result[k] = round(real_value);
		imag_result[k] = round(imag_value);
	}

	return real_result;
}

uint8_t FourierTransform::GetPeakFrequency(int16_t* freqArray)
{
	// gives frequency, relative to orignal sample rate in time space
	uint8_t peakFreq = 0;

	// finds the first peak frequency, might discover multiple peaks in the process, 
	// return the smaller frequency (larger ones are possible overtones)

	//128 elements in freqArray

	uint16_t peakValue = freqArray[0];

	// keep track of avg value;
	uint16_t averageValue = peakValue;

	// is this actually worth doing?
	uint8_t i = 1;


	// find largest value starting from lowIndex, ignore subsequent equivalent values (repeat peaks)
	for (i = 0; i < peakValue; i++)
	{
		uint16_t currentValue = freqArray[i];

		if (peakValue < currentValue)
		{
			peakValue = currentValue;
			peakFreq = i;
			averageValue = averageValue + currentValue;
		}
	}

	// Look at adjacent values to the peak value
	// see if we need to average a range of values to get real peak frequency (value is no 2^n)

	// search in both direction of the peak, look for if and when you cross total avg value
	// (this is the current heurtistic I'm using, this is subject to change)

	// + is to the right of this peak aka 0
	// - is to the left of this peak aka 0
	for (i = 0; i < 1; i++)
	{

	}

	return peakFreq;
}

int16_t* FourierTransform::GetFFT(uint16_t* inputArray)
{
	/*
	Radix 2 FFT

	Xk (DFT) of a n point sequence x_m with N = 2^t

	First step of FFT is

	N1 = 2 and N2 = 2^(t-1)

	Xk = Sum(m = 0; N/2 - 1)
		 {
			(x_2m * W^2mk) + W^k * Sum{
										x_2m+1 * W^2mk
									  }
		 }
*/

// Need to do in next PR

	return nullptr;
}
