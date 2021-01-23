/*
    Q: 925. Long Pressed Name
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
    bool isLongPressedName(string n, string t)
    {
        int nl = n.size();
        int tl = t.size();

        if (nl > tl)
        {
            return false;
        }

        for (int i = 0, j = 0; i < nl; i++)
        {
            if ((n[i] != t[j]) || (j >= tl))
            {
                return false;
            }

            int eCount = 1;
            while (n[i] == n[i + 1])
            {
                eCount++;
                i++;
            }

            int tCount = 0;
            while (n[i] == t[j])
            {
                tCount++;
                //printf("n[%d] = %c, t[%d] = %c, eCount = %d, tCount = %d\n", i, n[i], j, t[j], eCount, tCount);
                j++;
            }
            if (tCount < eCount)
            {
                return false;
            }
        }

        return true;
    }
};