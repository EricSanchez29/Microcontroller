#include <ArduinoCommByte.h>
#include <ArduinoCommNybl.h>
#include <FourDigitLed.h>

FourDigitLed led;

int analogSignal[128];

void setup()
{
  Serial.begin(9600);

  led = FourDigitLed::FourDigitLed(0, 11);

  // largest number I can represent
  led.Write(9999);
  led.ClearScreen();

}

void loop()
{
  //Serial.println(analogRead(0));
  for (int i = 0; i < 128; i++)
  {
    analogSignal[i] = analogRead(0);
  }
  
  for (int j = 0; j < 128; j++)
  {
    //led.Write(analogSignal[j]);
    Serial.println(analogSignal[j]);
  }

}
