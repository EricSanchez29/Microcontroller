#include "FourierTransform.h"
#include "SignalGenerator.h"
#include "ArduinoCommByte.h"
#include "ArduinoCommNybl.h"
#include "FourDigitLed.h" 

void setup() 
{
    uint16_t* wave_time; 
    uint16_t* wave_freq;
    uint8_t i;

    Serial.begin(9600);

    wave_time = SignalGenerator::GetWaveForm(8, 511.5);

    for (i = 0; i < 128; i++)
    {
        Serial.println(wave_time[i]);
    }

    wave_freq = FourierTransform::GetDFT(wave_time);

    for (i = 0; i < 128; i++)
    {
        Serial.println(wave_freq[i]);
    }
}

void loop() 
{ 
  
}
