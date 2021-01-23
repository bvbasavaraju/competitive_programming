/*
    Q: 7. Reverse Integer
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long int retVal = 0;
        bool n = (x < 0) ? true : false;

        long long int y = x;
        if (n)
        {
            y = y * -1;
        }

        while (y > 0)
        {
            retVal = (retVal * 10) + (y % 10);
            y = y / 10;
        }

        retVal = retVal > 0x7FFFFFFF ? 0 : retVal;
        if (retVal > 0 && n)
        {
            retVal *= -1;
        }
        return retVal;
    }
};