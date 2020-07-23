/****************************************************
Date: July 23rd

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/
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
    Q: Single Number III

    Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
    Find the two elements that appear only once.

    Example:
        Input:  [1,2,1,3,2,5]
        Output: [3,5]

    Note:
        The order of the result is not important. So in the above example, [5, 3] is also correct.
        Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        //O(1) space
        int xored = 0;
        for (int n : nums)
        {
            xored ^= n;
        }

        int bit = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (xored & (1 << i))
            {
                bit = i;
                break;
            }
        }

        int first = 0;
        for (int n : nums)
        {
            if (n & (1 << bit))
            {
                first ^= n;
            }
        }

        int second = xored ^ first;

        return {first, second};

        /* O(n) - space
    
    unordered_map<int, int> frq;
    for(int n : nums)
    {
      frq[n]++;
    }
    
    vector<int> ans;
    for(auto it = frq.begin(); it != frq.end(); ++it)
    {
      if(it->second == 1)
      {
        ans.push_back(it->first);
      }
    }
    
    return ans;*/
    }
};