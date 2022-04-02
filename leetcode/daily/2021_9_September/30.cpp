/****************************************************
Date: September 30th

https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/640/week-5-september-29th-september-30th/3993/
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
  Q: Partition to K Equal Sum Subsets

  Given an integer array nums and an integer k, return true if it is possible to divide this array into 
  k non-empty subsets whose sums are all equal.

  Example 1:
    Input: nums = [4,3,2,3,5,2,1], k = 4
    Output: true
    Explanation: 
      It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

  Example 2:
    Input: nums = [1,2,3,4], k = 3
    Output: false

  Constraints:
    1 <= k <= nums.length <= 16
    1 <= nums[i] <= 104
    The frequency of each element is in the range [1, 4].

  Hide Hint #1  
    We can figure out what target each subset must sum to. Then, let's recursively search, 
    where at each call to our function, we choose which of k subsets the next value will join.
*/

class Solution 
{
private:
  bool isPossible(vector<int>& nums, vector<bool>& visited, int target, int currentSum, int p, int k)
  {
    if(k == 1)
    {
      return true;
    }
    
    if(currentSum == target)
    {
      return isPossible(nums, visited, target, 0, 0, k-1);
    }
    
    for(int i = p; i < nums.size(); ++i)
    {
      if(visited[i] || (currentSum + nums[i] > target))
      {
        continue;
      }
      
      visited[i] = true;
      if(isPossible(nums, visited, target, currentSum + nums[i], i+1, k))
      {
        return true;
      }
      
      visited[i] = false;
    }
    
    return false;
  }
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) 
  {
    int sum = 0;
    for(int& n : nums)
    {
      sum += n;
    }
    
    if (sum % k > 0)
    {
      return false;
    }
    
    vector<bool> visited(nums.size(), false);
    return isPossible(nums, visited, sum / k, 0, 0, k);
  }
};