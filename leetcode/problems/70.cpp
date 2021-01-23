/*
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Ex:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps

Link:   https://leetcode.com/problems/climbing-stairs/
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution_t
{
public:
    int climbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }

        vector<int> stepsCount(n, 0);

        stepsCount[0] = 1;
        stepsCount[1] = 2;
        for (int i = 2; i < n; i++)
        {
            stepsCount[i] = stepsCount[i - 1] + stepsCount[i - 2];
        }

        return stepsCount[n - 1];
    }
};