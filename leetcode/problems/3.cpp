/*
    Q: 3. Longest Substring Without Repeating Characters
*/

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int retVal = 0;
        int l = s.size();
        for (int j = 0; j < l; j++)
        {
            map<int, int> m;
            int curMax = 0;
            for (int i = j; i < l; i++)
            {
                m[s[i]]++;
                if (m[s[i]] > 1)
                {
                    break;
                }
                else
                {
                    curMax++;
                }

                retVal = max(curMax, retVal);
            }
        }
        return retVal;
    }
};