/****************************************************
Date: April 15th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/
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
  Q:  Product of Array Except Self

  Given an array nums of n integers where n > 1,  
  return an array output such that output[i] is equal to 
  the product of all the elements of nums except nums[i].

  Example:
  Input:  [1,2,3,4]
  Output: [24,12,8,6]
  Constraint: It's guaranteed that the product of the elements of 
  any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

  Note: Please solve it without division and in O(n).

  Follow up:
  Could you solve it with constant space complexity? 
  (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution 
{
public:
  vector<int> productExceptSelf(vector<int>& nums) 
  {
    int p = 1;
    int zero_count = 0;
    for(int n : nums)
    {
      if(n != 0)
        p *= n;
      else
        zero_count++;
    }
    
    for(int& n : nums)
    {
      if(!zero_count)
      {
        n = p / n;
      }
      else
      {
        n = ((n == 0) && (zero_count == 1)) ? p : 0;
      }
    }
    
    return nums;
  }
};