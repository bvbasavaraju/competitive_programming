/****************************************************
Date: Feb 25th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
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
  Q: Shortest Unsorted Continuous Subarray

  Given an integer array nums, you need to find one continuous subarray that 
  if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

  Return the shortest such subarray and output its length.

  Example 1:
    Input: nums = [2,6,4,8,10,9,15]
    Output: 5
    Explanation: 
      You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

  Example 2:
    Input: nums = [1,2,3,4]
    Output: 0

  Example 3:
    Input: nums = [1]
    Output: 0

  Constraints:
    1 <= nums.length <= 104
    -105 <= nums[i] <= 105

  Follow up: Can you solve it in O(n) time complexity?
*/
class Solution 
{
public:
  int findUnsortedSubarray(vector<int>& nums) 
  {
    int l = nums.size();
    
    int sp = 0;
    int ep = l-1;
    for(int& i = sp; (i < l-1) && (nums[i] <= nums[i+1]); ++i)
    {
      ;
    }
    
    for(int& i = ep; (i > 0) && (nums[i] >= nums[i-1]); --i)
    {
      ;
    }
    
    int ans = 0;
    if(ep > sp)
    {
      int maxi = INT_MIN;
      int mini = INT_MAX;
      for(int i = sp; i <= ep; ++i)
      {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
      }
      
      for(int& i = sp; (i >= 0) && (nums[i] > mini) ; --i)
      {
        ;
      }
      
      for(int& i = ep; (i < l) && (nums[i] < maxi); ++i)
      {
        ;
      }
      
      ans = ep - sp - 1;
    }
    
    return ans;
  }
};