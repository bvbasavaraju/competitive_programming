/****************************************************
Date: June 10th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/
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
  Q: Search Insert Position

  Given a sorted array and a target value, return the index if the target is found.
  If not, return the index where it would be if it were inserted in order.
  You may assume no duplicates in the array.

  Example 1:
    Input: [1,3,5,6], 5
    Output: 2

  Example 2:
    Input: [1,3,5,6], 2
    Output: 1

  Example 3:
    Input: [1,3,5,6], 7
    Output: 4

  Example 4:
    Input: [1,3,5,6], 0
    Output: 0
*/

class Solution 
{
public:
  int searchInsert(vector<int>& nums, int target) 
  {
    int p;
    int l = 0;
    int r = nums.size() - 1;
    
    while(l <= r)
    {
      int m = l + (r - l)/2;
      
      p = m;
      if(nums[m] == target)
      {
        break;
      }
      
      if(nums[m] < target)
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    
    if(nums[p] == target)
    {
      return p;
    }
    else if(target > nums[p])
    {
      ++p;
    }
    else if(p > 0)
    {
      --p;
    }
    
    if((p < nums.size()) && (nums[p] < target))
    {
      p++;
    }
    
    return p;
  }
};