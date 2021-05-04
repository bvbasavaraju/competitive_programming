/****************************************************
Date: May 4th

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
  Q: Non-decreasing Array

  Given an array nums with n integers, your task is to check if it could become 
  non-decreasing by modifying at most one element.

  We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

  Example 1:
    Input: nums = [4,2,3]
    Output: true
    Explanation:
      You could modify the first 4 to 1 to get a non-decreasing array.

  Example 2:
    Input: nums = [4,2,1]
    Output: false
    Explanation:
      You can't get a non-decreasing array by modify at most one element.

  Constraints:
    n == nums.length
    1 <= n <= 104
    -105 <= nums[i] <= 105
*/
class Solution 
{
public:
  bool checkPossibility(vector<int>& nums) 
  {
    int modified = 0;
    for (int i = 1, prev = nums[0]; i < nums.size(); i++) 
    {
      if (nums[i] < prev && modified++) 
      {
        return false;
      }
      
      if (nums[i] < prev && i - 2 >= 0 && nums[i - 2] > nums[i]) 
      {
        continue;
      }
      
      prev = nums[i];
    }
    
    return true;
  }
};