#include "TrigFunctions.h"

double TrigFunctions::Cosine(double theta)
{
    // do I want to support any value?
    if ( (theta < 0) && (theta > twoPi))
    {
        return 100;
    }

    if (theta <= halfPi)
    {
        return lookupValue(theta);
    }
    else if ((theta > halfPi) && (theta < (my_pi)))
    {
        theta = theta - halfPi;

        theta = halfPi - theta;

        return lookupValue(theta) * -1;
    }
    else if ((theta > halfPi) && (theta < (my_pi)))
    {
        theta = theta - my_pi;

        return lookupValue(theta) * -1;
    }
    else // 3pi/2 < theta <= 2pi
    {
        theta = theta - my_pi - halfPi;

        return lookupValue(theta);
    }
}


double TrigFunctions::lookupValue(double phi)
{
    int index = (int)(phi * 10);

    // table has 158 values;
    return _cosineValues[index];
}
