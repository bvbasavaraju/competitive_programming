/*
    Q: 11. Container With Most Water
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
    int maxArea(vector<int> &h)
    {
        int l = h.size();
        int i = 0;
        int j = l - 1;

        int retVal = 0;
        while (i != j)
        {
            int a = min(h[i], h[j]) * (j - i);

            if (h[i] <= h[j])
            {
                i++;
            }
            else
            {
                j--;
            }

            retVal = max(retVal, a);
        }

        return retVal;
    }
};