/*
    Q: 459. Repeated Substring Pattern
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
    bool repeatedSubstringPattern(string s)
    {
        int l = s.size();
        if (l <= 1)
        {
            return false;
        }

        int rCount = 0;
        bool parsed = false;
        for (int i = 1; i < l; i++)
        {
            string t1 = s.substr(0, i);

            rCount = 1;
            int ssl = t1.size();
            for (int j = ssl; j < l; j = j + ssl)
            {
                string t2 = s.substr(j, ssl);
                if (t1 != t2)
                {
                    break;
                }

                rCount++;

                if ((j + ssl) == l)
                {
                    parsed = true;
                }
            }

            if (parsed)
            {
                break;
            }
        }

        return (rCount > 1) ? true : false;
    }
};