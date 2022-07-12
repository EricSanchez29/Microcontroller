#include "FourDigitLed.h"
#include "ArduinoByteComm.h"  


/*
 * // Instead of mapping wires here, just connect them so the ports line up where the segement lines are threated as a byte
 *                                                                                and the control lines are treated as half a byte
              // segment name:  a, b, c, d, e,  f, g, dot
const int digitSegmentPins[] = {11, 7, 4, 2, 1, 10, 5, 3};

       // digits left to right:  1, 2, 3, 4
const int digitSelectPins[] = { 12, 9, 8, 6};
// since common cathodes,
// digits are selected by low state
*/

unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() 
{
  // Set all digital pins as output:
  for (int i = 0; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("wtf");

  // loggin is messed up because it uses pin 0 and 1
  
  delay(3000);

  ArduinoByteComm comm = ArduinoByteComm::ArduinoByteComm(4, 11);

  // select digit (least significant figure)
  digitalWrite(0, true);
  digitalWrite(1, true);
  digitalWrite(2, true);
  digitalWrite(3, false);



/*
  // 7
  digitalWrite(4, true);
  digitalWrite(5, true);
  digitalWrite(6, true);
  digitalWrite(7, false);
  digitalWrite(8, false);
  digitalWrite(9, false);
  digitalWrite(10, false);
  digitalWrite(11, false);
  digitalWrite(12, false);

  delay(2000);
*/
  

  // "7" -> 
  comm.Write(B11100000);
  delay(2000);


  // 7 gets converted to B10000000

  int a = ConvertToFourDigitLed::ConvertInt(7);

  Serial.println(a, BIN);
  
  comm.Write(a);

  delay(2000);


  // A
  //comm.Write(B11101111);
  

  delay(4000);

  // blank
  digitalWrite(4, false);
  digitalWrite(5, false);
  digitalWrite(6, false);
  digitalWrite(7, false);
  digitalWrite(8, false);
  digitalWrite(9, false);
  digitalWrite(10, false);
  digitalWrite(11, false);
  digitalWrite(12, false);
  delay(1000);

  digitalWrite(3, true);
/*
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
*/

/*
  // upside down A with dot
  comm.Write(B00000000);

  delay(3000);
*/
  
}

void loop() 
{

  
  //byte a = ConvertToFourDigitLed::SelectDigit(1);
  
  
  
  //byte b = ConvertToFourDigitLed::ConvertInt(2);

  //Serial.println(b);
}
