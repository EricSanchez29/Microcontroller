#include <ArduinoCommByte.h>
#include <ArduinoCommNybl.h>
#include <FourDigitLed.h>

FourDigitLed led;

void setup()
{
  //Serial.begin(9600);

  led = FourDigitLed::FourDigitLed(0, 11);

  // largest number I can represent
  led.Write(9999);
  led.ClearScreen();

}

void loop()
{
  //Serial.println(analogRead(0));

  led.Write((uint16_t)analogRead(0));
}
