/****************************************************
Date: May 30th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/
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
  Q: Maximum Gap

  Given an integer array nums, return the maximum difference between two successive elements 
  in its sorted form. If the array contains less than two elements, return 0.

  You must write an algorithm that runs in linear time and uses linear extra space.

  Example 1:
    Input: nums = [3,6,9,1]
    Output: 3
    Explanation:
      The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

  Example 2:
    Input: nums = [10]
    Output: 0
    Explanation:
      The array contains less than 2 elements, therefore return 0.

  Constraints:
    1 <= nums.length <= 104
    0 <= nums[i] <= 109
*/
class Solution 
{
public:
  int maximumGap(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    int ans = 0;
    
    int l = nums.size();
    for(int i = 1; i < l; ++i)
    {
      ans = max(ans, (nums[i] - nums[i-1]));
    }
    
    return ans;
  }
};