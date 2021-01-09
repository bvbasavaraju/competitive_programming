/****************************************************
Date: July 11th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
    Q: Subsets

    Given a set of distinct integers, nums, return all possible subsets (the power set).
    Note: The solution set must not contain duplicate subsets.

    Example:
        Input: nums = [1,2,3]
        Output:
            [
            [3],
            [1],
            [2],
            [1,2,3],
            [1,3],
            [2,3],
            [1,2],
            []
            ]
*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int l = nums.size();
        vector<vector<int>> ans;

        int total = 1 << l;
        for (int i = 0; i < total; ++i)
        {
            vector<int> n;

            int temp = i;
            int p = 0;
            while (temp)
            {
                if (temp & 0x01)
                {
                    n.push_back(nums[p]);
                }
                p++;
                temp >>= 1;
            }

            ans.push_back(n);
        }

        return ans;
    }
};