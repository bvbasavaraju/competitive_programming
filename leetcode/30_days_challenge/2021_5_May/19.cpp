/****************************************************
Date: May 19th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
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
  Q: Minimum Moves to Equal Array Elements II

  Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

  In one move, you can increment or decrement an element of the array by 1.

  Example 1:
    Input: nums = [1,2,3]
    Output: 2
    Explanation:
      Only two moves are needed (remember each move increments or decrements one element):
      [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

  Example 2:
    Input: nums = [1,10,2,9]
    Output: 16

  Constraints:
    n == nums.length
    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

class Solution1_t
{
public:
  int minMoves2(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    int median = nums[nums.size()/2];
    
    int ans = 0;
    for(int n : nums)
    {
      ans += abs(median-n);
    }
    
    return ans;
  }
};