
#include <TrigFunctions.h>

void setup()
{
  Serial.begin(9600);


  double halfPi = 1.57079632679;
/*
  Serial.println(halfPi);

  double listSize = 128.0;

  double stepSize = halfPi / listSize;
  Serial.println(stepSize);
  */

  int count = 0;

  for (double i = 0; i < halfPi; i = i + 0.01)
  {
    Serial.println();
    //Serial.print(i);
    
    Serial.print(TrigFunctions::Cosine(i));
    Serial.print(", ");
    count++;
  }
  Serial.println();
  Serial.println(count);

}

void loop()
{
  //Serial.println();
  //Serial.println(TrigFunctions::Cosine(1));
}
