//#include <cstdint>

#include <Arduino.h>

class SignalGenerator
{
	public:

		static uint16_t* GetWaveForm(uint16_t cycles, double amplitude);
};
