/****************************************************
Date: April 19th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: Search in Rotated Sorted Array
  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

  (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.
  Your algorithm's runtime complexity must be in the order of O(log n).

  Example 1:
  Input: nums = [4,5,6,7,0,1,2], target = 0
  Output: 4

  Example 2:
  Input: nums = [4,5,6,7,0,1,2], target = 3
  Output: -1
*/
class Solution 
{
public:
  int search(vector<int>& nums, int t) 
  {
    if(nums.size() <= 0)
    {
      return -1;
    }
    
    bool is_rotated = (nums[0] > nums.back());
    int l = 0;
    int h = nums.size() - 1;
    while(l <= h)
    {
      int m = l + (h - l)/2;
      if(nums[m] == t)
      {
        return m;
      }
      
      if(nums[l] <= nums[m])  //Left part is not rotated!
      {
        if(nums[l] <= t && nums[m] > t) // And within the non rotated portion! serch in this portion!
        {
          h = m - 1;
        }
        else
        {
          l = m + 1;
        }
      }
      else
      {
        // if left part is rotated! and number is outside the left rotated portion!
        if(nums[l] > t && nums[m] < t)
        {
          l = m + 1;
        }
        else
        {
          h = m - 1;
        }
      }
    }
    
    return -1;
  }
};