// constants won't change. Used here to set a pin number:
const int arraySize =  5;// the number of the LED pin

// Variables will change:
int ledState[5];             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:

  for (int j = 0; j < arraySize; j++)
  {
    pinMode(ledState[j], OUTPUT); 
  }
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    for (int i = 0; i < 5; i++)
    {
      
      if (ledState[i] == LOW) 
      {
        ledState[i] = HIGH;
      } else 
      {
        ledState[i] = LOW;
      }

      digitalWrite(i, ledState[i]);
    }

    
    // if the LED is off turn it on and vice-versa:
    

    // set the LED with the ledState of the variable:
    
  }
}
