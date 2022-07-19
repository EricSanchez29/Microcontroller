#include <FourDigitLed.h>

#include <ArduinoComm.h>


FourDigitLed led;

void setup()
{
  // put your setup code here, to run once:

  //Serial.begin(9600);

  led = FourDigitLed::FourDigitLed(0, 11);

  // largest number I can represent
  led.Write(9999);
  led.ClearScreen();

}

void loop()
{
  // put your main code here, to run repeatedly:

  //Serial.println(analogRead(0));

  //led.Write((uint16_t)analogRead(0));
  led.Write(888);
  led.Write(6661);
  

}
