/****************************************************
Date: June 21st

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3368/
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
#include <string_view>

using namespace std;

/*
    Q: Single Number II

    Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:
        Input: [2,2,3,2]
        Output: 3

    Example 2:
        Input: [0,1,0,1,0,1,99]
        Output: 99
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto n : nums)
        {
            m[n]++;
        }

        int ans = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second == 1)
            {
                ans = it->first;
                break;
            }
        }

        return ans;
    }
};