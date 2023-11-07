
#include <TrigFunctions.h>

void setup()
{
  Serial.begin(9600);

  double dubPi = 6.28318530718;
  double halfPi = 1.57079632679;
/*
  Serial.println(halfPi);

  double listSize = 128.0;

  double stepSize = halfPi / listSize;
  Serial.println(stepSize);
  

  int errorCount = 0;
  double myAnswer = 0;
  double answer = 0;
  double diff = 0;
  */

  double test;

  // generate a large array of random numbers to calculate cos


  Serial.println("Testing speed");

  for (int j = 0; j < 1000; j++)
  {
    for (double i = 0; i < dubPi; i = i + 0.01)
    {
  
      test = TrigFunctions::Cosine(i);
      
      
      
      /*
      Serial.print(i);
      Serial.print(", ");
      Serial.print(myAnswer);
      Serial.print(", ");
      Serial.print(answer);
  
      diff = answer - myAnswer;
  
      Serial.print(", ");
      Serial.print(diff);
      
      if ((diff >= 0.1) || (diff <= -0.1 ))
      {
       errorCount++; 
      }
      */
  
    }
  }
  Serial.println("Done with My lib");

  for (int j = 0; j < 1000; j++)
  {
    for (double i = 0; i < dubPi; i = i + 0.01)
    {
  
      test = cos(i);
  
    }
  }

  Serial.println();
  Serial.println("Done with Arduino lib");
  
  //Serial.println();
  //Serial.println(errorCount);
  

}

void loop()
{
  //Serial.println();
  //Serial.println(TrigFunctions::Cosine(1));
}
