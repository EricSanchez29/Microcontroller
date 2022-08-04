#include "FourierTransform.h"
#include "SignalGenerator.h"
#include "ArduinoCommByte.h"
#include "ArduinoCommNybl.h"
#include "FourDigitLed.h" 

/*
    Right now I am just seeing how much space this takes up when its compiled for arduino
    
    Sketch uses 3424 bytes (11%) of program storage space. Maximum is 30720 bytes.
    Global variables use 700 bytes (34%) of dynamic memory, leaving 1348 bytes for local variables. Maximum is 2048 bytes.


    Will need to add code to communicate with microphone
    // So far I seem to have enough storage space, dynamic memory might be used up?
*/


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
