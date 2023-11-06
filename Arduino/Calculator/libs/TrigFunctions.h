#ifndef TRIG_H
#define TRIG_H

const double my_pi = 3.14159265359;
const double halfPi = 1.57079632679;
const double twoPi = 6.28318530718;

// generate this table using some other code, not in this file
const double _cosineValues[] = 
{
      1,
      0.70710678118,
      0
};

class TrigFunctions
{
  public:

    // theta is in radians
    static double Cosine(double theta);

    TrigFunctions() = delete;

  private:
    
    // after theta has been converted to a value that exists in the table, look it up
    static double lookupValue(double phi);
    
};

#endif