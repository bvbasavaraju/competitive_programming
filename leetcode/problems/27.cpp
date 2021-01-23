/*
    Q: 27. Remove Element
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
    int removeElement(vector<int> &nums, int val)
    {
        int ns = nums.size();
        int dc = 0;
        for (int i = 0; i < ns; i++)
        {
            if (val == nums[i])
            {
                ns--;
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return ns;
    }
};