/****************************************************
Date: April 25th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3310/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: Jump Game

  Given an array of non-negative integers, you are initially positioned at the first index of the array.
  Each element in the array represents your maximum jump length at that position.
  Determine if you are able to reach the last index.

  Example 1:
  Input: [2,3,1,1,4]
  Output: true
  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

  Example 2:
  Input: [3,2,1,0,4]
  Output: false
  Explanation: You will always arrive at index 3 no matter what. Its maximum
              jump length is 0, which makes it impossible to reach the last index.
*/

class Solution 
{  
public:  
  bool canJump(vector<int>& nums) 
  {
    if(nums.empty())
    {
      return false;
    }
    
    int can_reach = 0;
    for(int i = 0; i <= can_reach; ++i)
    {
      if(i >= nums.size() - 1)
      {
        return true;
      }
      
      can_reach = max(can_reach, i + nums[i]);
    }
    
    return false;
  }
};