/*
    Q: 12. Integer to Roman
    //Time Limit Exceeded - need to optimize the code!
    //TODO - optimize!!
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
    vector<vector<int>> threeSum(vector<int> &n)
    {
        int nl = n.size();
        vector<vector<int>> retVal;
        for (int i = 0; i < nl - 2; i++)
        {
            for (int j = i + 1; j < nl - 1; j++)
            {
                for (int k = j + 1; k < nl; k++)
                {
                    if (n[i] + n[j] + n[k] == 0)
                    {
                        vector<int> s = {n[i], n[j], n[k]};
                        sort(s.begin(), s.end());
                        retVal.push_back(s);
                    }
                }
            }
        }

        vector<vector<int>> result;
        if (retVal.size() > 0)
        {
            sort(retVal.begin(), retVal.end());

            result.push_back(retVal[0]);
            for (int i = 1; i < retVal.size(); i++)
            {
                if (retVal[i] != result[result.size() - 1])
                {
                    result.push_back(retVal[i]);
                }
            }
        }

        return result;
    }
};