/****************************************************
Date: May 25th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/
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
  Q: Contiguous Array
  Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

  Example 1:
    Input: [0,1]
    Output: 2
    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

  Example 2:
    Input: [0,1,0]
    Output: 2
    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
    
  Note: The length of the given binary array will not exceed 50,000.
*/

class Solution 
{
public:
  int findMaxLength(vector<int>& nums) 
  {
    int l = nums.size();
    if(l <= 0)
    {
      return 0;
    }
    
    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;
    m[0] = -1;    //if sum is 0, then its position is -1; This is the initial value
    for(int i = 0; i < l; ++i)
    {
      sum += nums[i] == 1 ? 1 : -1; // Add 1 for 1 and -1 for 0
      
      if(m.find(sum) == m.end())
      {
        m[sum] = i; //If sum not found add position of the sum to map, 
      }
      else
      {
        ans = max(ans, i - m[sum]); // If found, then substract the previous position with the current and check for max
      }
    }
    
    return ans;
  }
};