/****************************************************
Date: April 29th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/597/week-5-april-29th-april-30th/3726/
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
  Q: Find First and Last Position of Element in Sorted Array

  Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
  If target is not found in the array, return [-1, -1].
  Follow up: Could you write an algorithm with O(log n) runtime complexity?

  Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

  Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
  
  Example 3:
    Input: nums = [], target = 0
    Output: [-1,-1]

  Constraints:
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109
*/

class Solution 
{
private:
  int getPosition(vector<int>& nums, int target)
  {
    int l = 0;
    int h = nums.size()-1;
    
    int ans = -1;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(nums[m] >= target)
      {
        ans = m;
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return ans;
  }
    
public:
  vector<int> searchRange(vector<int>& nums, int target) 
  {
    int l = getPosition(nums, target);
    int h = -1;
    if((l >= 0) && (nums[l] == target))
    {
      if(nums[nums.size()-1] == nums[l])
      {
        h = nums.size()-1;
      }
      else
      {
        h = getPosition(nums, target+1) - 1;
      }
    }
    
    if(h < 0)
    {
      return {-1, -1};
    }
    
    return {l, h};
  }
};