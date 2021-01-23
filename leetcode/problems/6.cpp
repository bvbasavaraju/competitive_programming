/*
    Q: 6. ZigZag Conversion
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int sl = s.size();
        if ((sl <= numRows) || (numRows <= 1))
        {
            return s;
        }

        vector<vector<char>> rChar(numRows, vector<char>());
        int i = 0;
        int j = 0;
        int direction = 0; // 0 -> increment, 1 -> decrement
        while (i < sl)
        {
            for (; j < (numRows - 1) && (i < sl); j++)
            {
                rChar[j].push_back(s[i++]);
            }

            for (; j > 0 && (i < sl); j--)
            {
                rChar[j].push_back(s[i++]);
            }
        }

        string retVal = "";
        for (i = 0; i < numRows; i++)
        {
            int l = rChar[i].size();
            for (j = 0; j < l; j++)
            {
                retVal += rChar[i][j];
            }
        }

        return retVal;
    }
};