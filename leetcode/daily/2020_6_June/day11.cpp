/****************************************************
Date: June 10th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/
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
  Q: Sort Colors

  Given an array with n objects colored red, white or blue, 
  sort them in-place so that objects of the same color are adjacent, 
  with the colors in the order red, white and blue.
  
  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

  Note: You are not suppose to use the library's sort function for this problem.

  Example:
    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

  Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's,
    then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with a one-pass algorithm using only constant space?
*/

class Solution 
{
public:
  void sortColors(vector<int>& nums) 
  {
    unordered_map<int, int> m;
    for(int n : nums)
    {
      m[n]++;
    }
    
    int x = 0;
    for(int i = 0; i < m[0]; ++i)
    {
      nums[x++] = 0;
    }
    
    for(int i = 0; i < m[1]; ++i)
    {
      nums[x++] = 1;
    }
    
    for(int i = 0; i < m[2]; ++i)
    {
      nums[x++] = 2;
    }
    /*int l = nums.size();
    
    int p0 = -1;
    int p1 = -1;
    int p2 = -1;
    
    for(int i = 0; i < l; ++i)
    {
      switch(nums[i])
      {
        case 0:
          if(p0 < 0 || p0 < i)
            p0 = i;
          break;

        case 1:
          if(p1 < 0 || p1 > i)
            p1 = i;
          break;

        case 2:
          if(p2 < 0 || p2 > i)
            p2 = i;
          break;
      }
      
      
      if(p0 > 0)
      {
        if(p1 > 0 && p0 > p1)
        {
          int temp = nums[p0];
          nums[p0] = nums[p1];
          nums[p1] = temp;
          
          temp = p0;
          p0 = p1;
          p1 = temp;
        }
        
        if(p2 > 0 && p0 > p2)
        {
          int temp = nums[p0];
          nums[p0] = nums[p2];
          nums[p2] = temp;
          
          temp = p0;
          p0 = p2;
          p2 = temp;
        }
      }
      
      if(p1 > 0)
      {
        if(p2 > 0 && p1 > p2)
        {
          int temp = nums[p1];
          nums[p1] = nums[p2];
          nums[p2] = temp;
          
          temp = p1;
          p1 = p2;
          p2 = temp;
        }
      }
    }*/
  }
};