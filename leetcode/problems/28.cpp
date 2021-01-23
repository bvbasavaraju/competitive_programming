/*
    Q: 28. Implement strStr()
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
    int strStr(string h, string n)
    {
        int hl = h.size();
        int nl = n.size();

        if (nl <= 0)
        {
            return 0;
        }

        for (int i = 0; i < hl; i++)
        {
            if (h[i] != n[0])
            {
                continue;
            }

            if (i + nl > hl)
            {
                return -1;
            }

            bool found = true;
            for (int j = 0; j < nl; j++)
            {
                if (h[i + j] != n[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                return i;
            }
        }

        return -1;
    }
};