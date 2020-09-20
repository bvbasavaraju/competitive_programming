/****************************************************
Date: Sept 11th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3453/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
    Q: Maximum Product Subarray

    Given an integer array nums, find the contiguous subarray within an array (containing at least one number) 
    which has the largest product.

    Example 1:
        Input: [2,3,-2,4]
        Output: 6
        Explanation: [2,3] has the largest product 6.

    Example 2:
        Input: [-2,0,-1]
        Output: 0
        Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;

        int p = 1;
        int d = 1;
        int n_count = 0;

        for (int n : nums)
        {
            if (n == 0)
            {
                p = 1;
                d = 1;
                n_count = 0;
            }
            else
            {
                if (n < 0)
                {
                    n_count++;
                }

                p *= n;

                if (p < 0)
                {
                    ans = max(p / d, ans);
                }
                else
                {
                    ans = max(p, ans);
                }

                if (n_count == 1)
                {
                    d = p;
                    n_count = INT_MIN;
                }
            }
        }

        return max(*max_element(nums.begin(), nums.end()), ans);
    }
};