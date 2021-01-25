/****************************************************
Date: Jan 25th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/
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
  Q: Check If All 1's Are at Least Length K Places Away

  Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

  Example 1:
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.

  Example 2:
    Input: nums = [1,0,0,1,0,1], k = 2
    Output: false
    Explanation: The second 1 and third 1 are only one apart from each other.

  Example 3:
    Input: nums = [1,1,1,1,1], k = 0
    Output: true

  Example 4:
    Input: nums = [0,1,0,1], k = 1
    Output: true

  Constraints:
    1 <= nums.length <= 105
    0 <= k <= nums.length
    nums[i] is 0 or 1

  Hide Hint #1  
    Each time you find a number 1, check whether or not it is K or more places away from the next one. If it's not, return false.
*/
class Solution 
{
public:
  bool kLengthApart(vector<int>& nums, int k) 
  {
    int l = nums.size();
    
    int prev_pos = INT_MIN;
    for(int i = 0; i < l; ++i)
    {
      if(nums[i] == 1)
      {
        if(prev_pos == INT_MIN)
        {
          prev_pos = i;
        }
        else
        {
          if((i-prev_pos-1) < k)
          {
            return false;
          }
          prev_pos = i;
        }
      }
    }
    
    return true;
  }
};