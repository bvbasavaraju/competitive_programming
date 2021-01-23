/*
    Q: 13. Roman to Integer
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int retVal = 0;
        int l = s.size();
        for (int i = l - 1; i >= 0; i--)
        {
            switch (s[i])
            {
            case 'I':
                retVal = (retVal < 3) ? (retVal + 1) : (retVal - 1);
                break;

            case 'V':
                retVal += 5;
                break;

            case 'X':
                retVal = (retVal < 30) ? (retVal + 10) : (retVal - 10);
                break;

            case 'L':
                retVal += 50;
                break;

            case 'C':
                retVal = (retVal < 300) ? (retVal + 100) : (retVal - 100);
                break;

            case 'D':
                retVal += 500;
                break;

            case 'M':
                retVal += 1000;
                break;
            }
        }

        return retVal;
    }
};