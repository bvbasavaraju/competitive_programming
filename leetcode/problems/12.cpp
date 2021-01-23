/*
    Q: 12. Integer to Roman
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution_t
{
private:
    enum Position_t
    {
        DIGIT_COUNT_ONE = 1,
        DIGIT_COUNT_TWO = 2,
        DIGIT_COUNT_THREE = 3,
    };

    void AddRomanString(const string &rS, int c, string &output)
    {
        if (c <= 0 || rS.size() <= 0)
        {
            return;
        }

        for (int i = 0; i < c; i++)
        {
            output += rS;
        }
    }

    void UpdateRomanSymbol(Position_t pos, int val, string &output)
    {
        string s = "";
        switch (val)
        {
        case 9:
            s = (pos == DIGIT_COUNT_ONE) ? "IX" : ((pos == DIGIT_COUNT_TWO) ? "XC" : "CM");
            break;

        case 8:
            s = (pos == DIGIT_COUNT_ONE) ? "VIII" : ((pos == DIGIT_COUNT_TWO) ? "LXXX" : "DCCC");
            break;

        case 7:
            s = (pos == DIGIT_COUNT_ONE) ? "VII" : ((pos == DIGIT_COUNT_TWO) ? "LXX" : "DCC");
            break;

        case 6:
            s = (pos == DIGIT_COUNT_ONE) ? "VI" : ((pos == DIGIT_COUNT_TWO) ? "LX" : "DC");
            break;

        case 5:
            s = (pos == DIGIT_COUNT_ONE) ? "V" : ((pos == DIGIT_COUNT_TWO) ? "L" : "D");
            break;

        case 4:
            s = (pos == DIGIT_COUNT_ONE) ? "IV" : ((pos == DIGIT_COUNT_TWO) ? "XL" : "CD");
            break;

        case 3:
            s = (pos == DIGIT_COUNT_ONE) ? "III" : ((pos == DIGIT_COUNT_TWO) ? "XXX" : "CCC");
            break;

        case 2:
            s = (pos == DIGIT_COUNT_ONE) ? "II" : ((pos == DIGIT_COUNT_TWO) ? "XX" : "CC");
            break;

        case 1:
            s = (pos == DIGIT_COUNT_ONE) ? "I" : ((pos == DIGIT_COUNT_TWO) ? "X" : "C");
            break;
        }

        output += s;
    }

public:
    string intToRoman(int num)
    {
        string retVal = "";

        int mCount = num / 1000;
        AddRomanString("M", mCount, retVal);

        num = num % 1000;
        int h = num / 100;
        UpdateRomanSymbol(DIGIT_COUNT_THREE, h, retVal);

        num = num % 100;
        int t = num / 10;
        UpdateRomanSymbol(DIGIT_COUNT_TWO, t, retVal);

        num = num % 10;
        UpdateRomanSymbol(DIGIT_COUNT_ONE, num, retVal);

        return retVal;
    }
};