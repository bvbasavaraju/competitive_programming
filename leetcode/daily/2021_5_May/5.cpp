/****************************************************
Date: May 5th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Jump Game II

  Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
  Each element in the array represents your maximum jump length at that position.
  Your goal is to reach the last index in the minimum number of jumps.
  You can assume that you can always reach the last index.

  Example 1:
    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation:
      The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

  Example 2:
    Input: nums = [2,3,0,1,4]
    Output: 2

  Constraints:
    1 <= nums.length <= 1000
    0 <= nums[i] <= 105
*/

class Solution 
{
public:
  int jump(vector<int>& nums) 
  {
    int n = nums.size();
    int step = 0; 
    int start = 0;
    int end = 0;
    
    while (end < n - 1) 
    {
      step++; 
      int maxend = end + 1;
      for (int i = start; i <= end; i++) 
      {
        if (i + nums[i] >= n - 1) 
        {
          return step;
        }
        
        maxend = max(maxend, i + nums[i]);
      }
      start = end + 1;
      end = maxend;
    }
    
    return step;
  }
};