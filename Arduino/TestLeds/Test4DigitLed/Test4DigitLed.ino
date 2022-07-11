
#include "FourDigitLed.h"

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
  // set all digital pins as output:
  for (int i = 0; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

  // select the first digit
  digitalWrite(digitSelectPins[0] - 1, LOW);
  digitalWrite(digitSelectPins[1] - 1, LOW);
  digitalWrite(digitSelectPins[2] - 1, LOW);
  digitalWrite(digitSelectPins[3] - 1, LOW);

  // write the number 8, with a dot

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(digitSegmentPins[i] - 1, HIGH);
  }
  
}

void loop() 
{
  
  // here is where you'd put code that needs to be running all the time.

  //unsigned long currentMillis = millis();

  byte a = ConvertToFourDigitLed::SelectDigit(1);
  byte b = ConvertToFourDigitLed::ConvertInt(3);

  int A = int(a);
  int B = int(b);

  Serial.begin(9600);
  Serial.println(a);
  Serial.println(A);
  Serial.println(B);

  

}

// hard coding this to certain pin number
// may want to create a library that lets you custom select the range of pin
// that you want to use to write a byte
void WriteByte(byte message)
{
  
  
  for (int i = 0; i < 8; i ++)
  {
    //Wr
  }
}
