/****************************************************
Date: July 8th

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
  Q: 3Sum

  Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
  Find all unique triplets in the array which gives the sum of zero.

  Note:
  The solution set must not contain duplicate triplets.

  Example:
    Given array nums = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

  Hide Hint #1  
    So, we essentially need to find three numbers x, y, and z such that they add up to the given value.
    If we fix one of the numbers say x, we are left with the two-sum problem at hand!
  Hide Hint #2  
    For the two-sum problem, if we fix one of the numbers, say
    x
    , we have to scan the entire array to find the next number
    y
    which is
    value - x
    where value is the input parameter. Can we change our array somehow so that this search becomes faster?
  Hide Hint #3  
    The second train of thought for two-sum is, without changing the array, can we use additional space somehow?
    Like maybe a hash map to speed up the search?
*/

class Solution 
{
private:
  bool isTargetPresent(vector<int>& nums, int s, int e, int target)
  {
    while(s <= e)
    {
      int m = s + (e-s)/2;
      
      if(nums[m] == target)
      {
        return true;
      }
      else if(nums[m] > target)
      {
        e = m - 1;
      }
      else
      {
        s = m + 1;
      }
    }
    
    return false;
  }
  
public:
  vector<vector<int>> threeSum(vector<int>& n) 
  {
    sort(n.begin(), n.end());
    
    int count = 1;
    vector<int> nums;
    for(int a : n)
    {
      if(nums.size() > 0)
      {
        if(nums.back() == a)
        {
          count++;  
        }
        else
        {
          count = 1;
        }
        
        if(count <= 3)
        {
          nums.push_back(a);
        }
      }
      else
      {
        nums.push_back(a);
      }
    }
    
    vector<vector<int>> result;
    int l = nums.size();
    for(int i = 0; i < l - 2; ++i)
    {
      for(int j = i + 1; j < l - 1; ++j)
      {
        int t = 0 - (nums[i] + nums[j]);  
        if(isTargetPresent(nums, j + 1, l - 1, t))
        {
          vector<int> v = {nums[i], nums[j], t};
          if((result.size() == 0) || (result.size() > 0 && v != result.back()))
          {
            result.push_back(v);
          }          
        }
      }
    }
    
    //now remove duplicates if any!
    l = result.size();
    if(l > 0)
    {
      sort(result.begin(), result.end());

      l = result.size();
      vector<vector<int>> ans;
      ans.push_back(result[0]);
      int j = 1;
      for(int i = 1; i < l; i++)
      {
        if(result[i] != ans.back())
        {
          ans.push_back(result[i]);
        }
      }

      return ans;
    }
    
    return result;
  }
};