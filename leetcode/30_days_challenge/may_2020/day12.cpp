/****************************************************
Date: May 12th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/
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
  Q: Single Element in a Sorted Array
  You are given a sorted array consisting of only integers where every element appears exactly twice,
  except for one element which appears exactly once. Find this single element that appears only once.

  Example 1:
    Input: [1,1,2,3,3,4,4,8,8]
    Output: 2

  Example 2:
    Input: [3,3,7,7,10,11,11]
    Output: 10

  Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution 
{
public:
  int singleNonDuplicate(vector<int>& nums) 
  {
    int s = nums.size();
    
    int l = 0;
    int h = s - 1;
    
    int ans = 0;
    while(l <= h)
    {
      int m = l + (h-l)/2;
      
      if(m % 2 == 0)
      {
        if((m > 0) && nums[m - 1] == nums[m])
          h = m - 1;
        else
        {
          ans = nums[m];
          if((m < s - 1) && (nums[m + 1] != nums[m]))
            break;
          else
            l = m + 1;
        }
      }
      else
      {
        if((m > 0) && nums[m - 1] == nums[m])
          l = m + 1;
        else
        {
          ans = nums[m];
          h = m - 1;
        }
      }
    }
    
    return ans;
  }
};