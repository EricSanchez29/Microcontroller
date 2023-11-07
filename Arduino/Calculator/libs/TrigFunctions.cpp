#include "TrigFunctions.h"

double TrigFunctions::Cosine(double theta)
{
    // do I want to support any value?
    if ( (theta < 0) && (theta >= twoPi))
    {
        return 100;
    }
    // use to mod (theta mod 2pi)

    if (theta < halfPi)
    {
        return lookupValue(theta);
    }
    else if ((theta >= halfPi) && (theta < (my_pi)))
    {
        theta = theta - halfPi;

        theta = halfPi - theta;

         double value = lookupValue(theta);

        // To avoid returning -0
        if (value == 0)
        {
            return 0;
        }

        return  value * -1;
    }
    else if ((theta >= my_pi) && (theta < (my_pi + halfPi)))
    {
        theta = theta - my_pi;

        double value = lookupValue(theta);

        // To avoid returning -0
        if (value == 0)
        {
            return 0;
        }

        return  value * -1;
    }
    else // 3pi/2 <= theta < 2pi
    {
        theta = theta - my_pi - halfPi;

        theta = halfPi - theta;

        return lookupValue(theta);
    }
}


double TrigFunctions::lookupValue(double phi)
{
    int index = (int)(phi * 100) + 1;

    // table has 158 values;
    return _cosineValues[index];
}
