/****************************************************
Date: April 4th

link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3286/
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
  Q:  Move Zeroes
  Given an array nums, write a function to move all 0's to the end of it 
  while maintaining the relative order of the non-zero elements.

  Example:
  Input: [0,1,0,3,12]
  Output: [1,3,12,0,0]

  Note:
  You must do this in-place without making a copy of the array.
  Minimize the total number of operations.
*/

class Solution 
{
public:
  void moveZeroes(vector<int>& nums) 
  {
    int l = nums.size();
    /*for(int i = 0; i < l - 1; ++i)
    {
      if(nums[i] != 0)
      {
        continue;
      }
      
      static int j = i + 1;
      for(; j < l; j++)
      {
        if(nums[j] == 0)
        {
          continue;
        }
        nums[i] = nums[j];
        nums[j++] = 0;
        break;
      }
      if(j == l)
      {
        break;
      }
    }*/
    for(int i = 0; i < l-1; ++i)
    {
      if(nums[i] != 0)
      {
        continue;
      }
      
      for(int j = i+1; j < l; j++)
      {
        if(nums[j] == 0)
        {
          continue;
        }
        nums[i] = nums[j];
        nums[j] = 0;
        break;
      }
    }
  }
};