/*
    Q: 8. String to Integer (atoi)
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int l = s.size();
        bool n = false;
        bool nonWhiteSpaceFound = false;
        long long int r = 0;
        for (int i = 0; i < l; i++)
        {
            char ch = s[i];
            if (ch == '-')
            {
                if (nonWhiteSpaceFound || ((i > 0) && (s[i - 1] == '+')))
                {
                    break;
                }
                n = true;
                nonWhiteSpaceFound = true;
                continue;
            }

            if (ch == '+')
            {
                if (nonWhiteSpaceFound || ((i > 0) && (s[i - 1] == '-')))
                {
                    break;
                }
                nonWhiteSpaceFound = true;
                continue;
            }

            if (ch == ' ')
            {
                if (nonWhiteSpaceFound)
                {
                    break;
                }
                continue;
            }

            if ((ch > '9') || (ch < '0'))
            {
                break;
            }
            else
            {
                r = (r * 10) + (ch - '0');
                nonWhiteSpaceFound = true;
                if (r > INT32_MAX)
                {
                    break;
                }
            }
        }

        if ((r > 0) && n)
        {
            r *= -1;
        }

        return (r < INT32_MIN) ? INT32_MIN : ((r > INT32_MAX) ? INT32_MAX : r);
    }
};