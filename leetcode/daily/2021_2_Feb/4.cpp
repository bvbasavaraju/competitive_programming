/****************************************************
Date: Feb 4th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
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
  Q: Longest Harmonious Subsequence

  We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
  Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
  A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

  Example 1:
    Input: nums = [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation:
      The longest harmonious subsequence is [3,2,2,2,3].

  Example 2:
    Input: nums = [1,2,3,4]
    Output: 2

  Example 3:
    Input: nums = [1,1,1,1]
    Output: 0

  Constraints:
    1 <= nums.length <= 2 * 104
    -109 <= nums[i] <= 109
*/

class Solution 
{
public:
  int findLHS(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    int ans = 0;
    for(int n : nums)
    {
      int possible_ans = 0;
      if(freq[n-1] > 0)
      {
        possible_ans = max(possible_ans, (freq[n-1] + freq[n]));
      }
      if(freq[n+1] > 0)
      {
        possible_ans = max(possible_ans, (freq[n+1] + freq[n]));
      }
      
      ans = max(ans, possible_ans);
    }
    
    return ans;
  }
};