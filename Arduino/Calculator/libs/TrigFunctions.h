#ifndef TRIG_H
#define TRIG_H

const double my_pi = 3.14159265359;
const double halfPi = 1.57079632679;
const double twoPi = 6.28318530718;

// generate this table using some other code, not in this file
const double _cosineValues[158] = 
{
      1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
1.00, 
0.99, 
0.99, 
0.99, 
0.99, 
0.99, 
0.99, 
0.99, 
0.98, 
0.98, 
0.98, 
0.98, 
0.98, 
0.97, 
0.97, 
0.97, 
0.97, 
0.96, 
0.96, 
0.96, 
0.96, 
0.95, 
0.95, 
0.95, 
0.94, 
0.94, 
0.94, 
0.93, 
0.93, 
0.92, 
0.92, 
0.92, 
0.91, 
0.91, 
0.90, 
0.90, 
0.90, 
0.89, 
0.89, 
0.88, 
0.88, 
0.87, 
0.87, 
0.86, 
0.86, 
0.85, 
0.85, 
0.84, 
0.84, 
0.83, 
0.83, 
0.82, 
0.81, 
0.81, 
0.80, 
0.80, 
0.79, 
0.78, 
0.78, 
0.77, 
0.76, 
0.76, 
0.75, 
0.75, 
0.74, 
0.73, 
0.72, 
0.72, 
0.71, 
0.70, 
0.70, 
0.69, 
0.68, 
0.67, 
0.67, 
0.66, 
0.65, 
0.64, 
0.64, 
0.63, 
0.62, 
0.61, 
0.61, 
0.60, 
0.59, 
0.58, 
0.57, 
0.57, 
0.56, 
0.55, 
0.54, 
0.53, 
0.52, 
0.51, 
0.51, 
0.50, 
0.49, 
0.48, 
0.47, 
0.46, 
0.45, 
0.44, 
0.44, 
0.43, 
0.42, 
0.41, 
0.40, 
0.39, 
0.38, 
0.37, 
0.36, 
0.35, 
0.34, 
0.33, 
0.32, 
0.32, 
0.31, 
0.30, 
0.29, 
0.28, 
0.27, 
0.26, 
0.25, 
0.24, 
0.23, 
0.22, 
0.21, 
0.20, 
0.19, 
0.18, 
0.17, 
0.16, 
0.15, 
0.14, 
0.13, 
0.12, 
0.11, 
0.10, 
0.09, 
0.08, 
0.07, 
0.06, 
0.05, 
0.04, 
0.03, 
0.02, 
0.01, 
0.00, 

};


/*
    The idea behind this was presented in a Youtube video by Kaze Emanuar
    He used this method of computing trig functions on an N64 which had limited memory and
    who's system had to make many of these simple calculations for graphics

    The idea of this implementation is to store only the values from the first quarter of the 
    cosine wave (0 through pi/2) and merely flip them appropriately for the other quarters (pi/2 through 2pi)

    I was planning on running this code on an arduino but there are some drawbacks from 
    using the platform (no doubles and so low very low precision, 2 decimal places after period)
    and their own cos implementation was much faster. I had an error of 0.1 for some values that were
    not in the first quarter, I attribute this to the precision of the table values themselves, i think
    a higher precision on values (and thus a larger table) would mean less errors.

    I may eventually change this with some other datatype which would allow greater precision
    on the arduino, like some kind of decimal datatype that I create myself
*/
class TrigFunctions
{
  public:

    // theta is in radians
    static double Cosine(double theta);

    // used to signal the class is static
    TrigFunctions() = delete;

  private:
    
    // after theta has been converted to a value that exists in the table, look it up
    static double lookupValue(double phi);
    
};

#endif