/****************************************************
Date: June 17th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/605/week-3-june-15th-june-21st/3781/
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
  Q: Number of Subarrays with Bounded Maximum

  We are given an array nums of positive integers, and two positive integers left and right (left <= right).
  Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in 
  that subarray is at least left and at most right.

  Example:
    Input: 
    nums = [2, 1, 4, 3]
    left = 2
    right = 3
    Output: 3
    Explanation: 
      There are three subarrays that meet the requirements: [2], [2, 1], [3].

  Note:
    left, right, and nums[i] will be an integer in the range [0, 109].
    The length of nums will be in the range of [1, 50000].
*/
class Solution 
{
public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
  {
    int ans = 0;
    int l = -1;
    int r = -1;
    
    for (int i=0; i < nums.size(); i++) 
    {
      if (nums[i] > right)
      {
        l = i;
      }
      
      if (nums[i] >= left)
      {
        r = i;
      }
      
      ans += (r - l);
    }
    
    return ans;
  }
};