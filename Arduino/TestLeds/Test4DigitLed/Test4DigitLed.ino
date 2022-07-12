#include "FourDigitLed.h"
#include "ArduinoByteComm.h"  

              // segment name:  a, b, c, d, e,  f, g, dot
const int digitSegmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3};

       // digits left to right:  1, 2, 3, 4
const int digitSelectPins[] = { 12, 9, 8, 6};
// since common cathodes,
// digits are selected by low state


// remvoe this?
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() 
{
  // Set all digital pins as output:
  for (int i = 0; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

   ArduinoByteComm comm = ArduinoByteComm::ArduinoByteComm(4, 11);

  // select digit (most significant figure)
  digitalWrite(0, false);
  digitalWrite(1, true);
  digitalWrite(2, true);
  digitalWrite(3, true);

  // "5"
  comm.Write(B10110110);

  // Select the first digit
//  SelectDigit(ConvertToFourDigitLed::SelectDigit((uint8_t)1));

  // Write the number 8
  //WriteByte(ConvertToFourDigitLed::ConvertInt((uint16_t)8));

  delay(2000);

  // "6"
  comm.Write(B10111110);

  delay(2000);

  // all bits on (including dot)
  comm.Write(B11111111);

  delay(2000);

  comm.Write(B11111110);

  delay(2000);

  digitalWrite(0, true);
}

void loop() 
{
  //unsigned long currentMillis = millis();


  byte a = ConvertToFourDigitLed::SelectDigit(1);
  byte b = ConvertToFourDigitLed::ConvertInt(2);

 //com.Write("");


/*
  int A = int(a);
  int B = int(b);

  Serial.begin(9600);
  Serial.println(a);
  Serial.println(A);
  Serial.println(B);
*/


 

  //select digit 1;

  //digitalWrite(0, HIGH);

  

  //com.Write(b);

}
