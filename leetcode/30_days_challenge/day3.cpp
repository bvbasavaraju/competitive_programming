/****************************************************
Date: April 3rd

link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3285/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
  Q:  Maximum Subarray

  Given an integer array nums, find the contiguous subarray 
  (containing at least one number) which has the largest sum and return its sum.

  Example:
  Input: [-2,1,-3,4,-1,2,1,-5,4],
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.

  Follow up:
  If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution 
{
public:
  int maxSubArray(vector<int>& n) 
  {
    int l = n.size();
    if(l <= 0)
    {
      return 0;
    }
    
    int sum = n[0];
    int result = sum;
    for(int i = 1; i < l; ++i)
    {
      sum = max(n[i], sum+n[i]);
      
      result = max(sum, result);
    }
    
    return result;
  }
};