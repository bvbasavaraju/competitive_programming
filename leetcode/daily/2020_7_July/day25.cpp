/****************************************************
Date: July 25th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3393/
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
  Q: Find Minimum in Rotated Sorted Array II

  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
  (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

  Find the minimum element.
  The array may contain duplicates.

  Example 1:
    Input: [1,3,5]
    Output: 1
  
  Example 2:
    Input: [2,2,2,0,1]
    Output: 0
  
  Note:
    This is a follow up problem to Find Minimum in Rotated Sorted Array.
    Would allow duplicates affect the run-time complexity? How and why?
*/

class Solution 
{
private:
  int getMin(int lo, int hi, vector<int>& nums)
  {
    int ans = min(nums[lo], nums[hi]);
    for(int i = lo + 1; i < hi; ++i)
    {
      if(nums[i] < ans)
      {
        ans = nums[i];
        break;
      }
    }
    
    return ans;
  }
  
public:
  int findMin(vector<int>& nums) 
  {
    int lo = 0;
    int hi = nums.size() - 1;
    
    int ans = min(nums[lo], nums[hi]);
    while(lo <= hi)
    {
      int mid = lo + (hi - lo)/2;
      
      if(nums[mid] < ans)
      {
        ans = nums[mid];
      }
      
      if((nums[lo] < nums[mid]) && (nums[mid] > nums[hi]))
      {
        lo = mid + 1;
      }
      else
      {
        if((nums[lo] == nums[mid]) && (getMin(lo, mid, nums) == nums[mid]))
        {
          lo = mid + 1;
        }
        else
        {
          hi = mid - 1;
        }
      }
    }
    
    return ans;
  }
};