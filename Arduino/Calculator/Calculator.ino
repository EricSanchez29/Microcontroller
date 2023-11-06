
#include <TrigFunctions.h>

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < 32; i++)
  {
    Serial.println(cos(i));
  }

  

}

void loop()
{
  
}
