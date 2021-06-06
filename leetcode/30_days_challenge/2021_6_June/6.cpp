/****************************************************
Date: June 6th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
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
  Q: Longest Consecutive Sequence

  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
  You must write an algorithm that runs in O(n) time.

  Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation:
      The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

  Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9

  Constraints:
    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

class Solution 
{
public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> s(nums.begin(), nums.end());
    
    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      if(s.find(nums[i]-1) == s.end())
      {
        int n = nums[i];
        int count = 1;
        while(s.find(n+1) != s.end())
        {
          n++;
          count++;
        }
        
        ans = max(ans, count);
      }
    }
    
    return ans;
  }
};