/*
    Q: 14. Longest Common Prefix
*/

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string retVal = "";
        int nStrs = strs.size();

        if (nStrs > 0)
        {
            sort(strs.begin(), strs.end(), [](const string &s1, const string &s2) -> bool { return (s1.size() < s2.size()); });

            string f = strs[0];
            int fl = f.size();
            for (int x = 0; x < fl; x++)
            {
                char ch = f[x];
                for (int i = 1; i < nStrs; i++)
                {
                    if (ch != strs[i][x])
                    {
                        return retVal;
                    }
                }

                retVal += ch;
            }
        }

        return retVal;
    }
};