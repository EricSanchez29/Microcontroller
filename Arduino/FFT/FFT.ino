#include "FourierTransform.h"
//#include "ArduinoCommByte.h"
//#include "ArduinoCommNybl.h"
//#include "FourDigitLed.h" 

/*
    Right now I am just seeing how much space this takes up when its compiled for arduino
    
    Sketch uses 3424 bytes (11%) of program storage space. Maximum is 30720 bytes.
    Global variables use 700 bytes (34%) of dynamic memory, leaving 1348 bytes for local variables. Maximum is 2048 bytes.


    Will need to add code to communicate with microphone
    // So far I seem to have enough storage space, dynamic memory might be used up?
*/


//FourDigitLed led;
uint16_t analogSignal[128];

void setup() 
{ 
    Serial.begin(9600);
    
    //led = FourDigitLed::FourDigitLed(0, 11);

    // overflow
    //led.Write(10000);
    //led.ClearScreen();

    Serial.println("Start Reading");
    //Serial.println(analogRead(0));
    for (int i = 0; i < 128; i++)
    {
      // add delay to have measurements in the ranges of 100 - 900 Hz
      delay(20);
      analogSignal[i] = analogRead(0);
    }
    Serial.println("End Reading");

    int32_t* waveFreq;

    waveFreq = FourierTransform::DFT(analogSignal);
    Serial.println("Time signal");
    for (int j = 0; j < 128; j++)
    {
      //led.Write(analogSignal[j]);
      Serial.println(analogSignal[j]);
    }
    Serial.println("Freq Signal");
  for (int j = 0; j < 128; j++)
  {
//    led.Write(analogSignal[j]);
    Serial.println(waveFreq[j]);
  }


  Serial.println(FourierTransform::GetPeakFrequency(waveFreq));
    //led.Write(FourierTransform::GetPeakFrequency(waveFreq));
}

 void loop()
{
}
