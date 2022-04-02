/****************************************************
Date: May 3rd

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Running Sum of 1d Array

  Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
  Return the running sum of nums.

  Example 1:
    Input: nums = [1,2,3,4]
    Output: [1,3,6,10]
    Explanation:
      Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

  Example 2:
    Input: nums = [1,1,1,1,1]
    Output: [1,2,3,4,5]
    Explanation:
      Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

  Example 3:
    Input: nums = [3,1,2,10,1]
    Output: [3,4,6,16,17]

  Constraints:
    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

  Hide Hint #1  
    Think about how we can calculate the i-th number in the running sum from the (i-1)-th number.
*/

class Solution 
{
public:
  vector<int> runningSum(vector<int>& nums) 
  {
    int l = nums.size();
    
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i = 1; i < l; ++i)
    {
      ans.push_back(ans.back() + nums[i]);
    }
    
    return ans;
  }
};