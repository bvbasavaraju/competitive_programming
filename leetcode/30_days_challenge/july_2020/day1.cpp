/****************************************************
Date: July 1st

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
    Q: Arranging Coins

    You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
    Given n, find the total number of full staircase rows that can be formed.
    n is a non-negative integer and fits within the range of a 32-bit signed integer.

    Example 1:
        n = 5
        The coins can form the following rows:
        ¤
        ¤ ¤
        ¤ ¤
        Because the 3rd row is incomplete, we return 2.
    
    Example 2:
        n = 8
        The coins can form the following rows:
        ¤
        ¤ ¤
        ¤ ¤ ¤
        ¤ ¤
        Because the 4th row is incomplete, we return 3.
*/

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int ans = 0;
        int count = 0;
        while (count < n)
        {
            if ((n - count) < (ans + 1))
            {
                break;
            }

            ans++;
            count += ans;

            if ((n - count) <= 0)
            {
                break;
            }
        }

        return ans;
    }
};