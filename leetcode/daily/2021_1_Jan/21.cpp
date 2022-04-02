/****************************************************
Date: Jan 21th

link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3606/
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
  Q: Find the Most Competitive Subsequence

  Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
  An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
  We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, 
  subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

  Example 1:
    Input: nums = [3,5,2,6], k = 2
    Output: [2,6]
    Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.

  Example 2:
    Input: nums = [2,4,3,3,5,4,9,6], k = 4
    Output: [2,3,3,4]

  Constraints:
    1 <= nums.length <= 105
    0 <= nums[i] <= 109
    1 <= k <= nums.length

  Hide Hint #1  
    In lexicographical order, the elements to the left have higher priority than those that come after. 
    Can you think of a strategy that incrementally builds the answer from left to right?
*/

class Solution 
{
public:
  vector<int> mostCompetitive(vector<int>& nums, int k) 
  {
    int l = nums.size();

    vector<int> ans;
    for(int i = 0; i < l; ++i)
    {
      while(!ans.empty() && (ans.back() > nums[i]) && ((ans.size() - 1 + l - i) >= k))
      {
        ans.pop_back();
      }

      if(ans.size() < k)
      {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};