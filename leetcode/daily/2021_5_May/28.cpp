/****************************************************
Date: May 28th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/
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
  Q: Maximum Erasure Value

  You are given an array of positive integers nums and want to erase a subarray 
  containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

  Return the maximum score you can get by erasing exactly one subarray.
  An array b is called to be a subarray of a if it forms a contiguous subsequence of a, 
  that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

  Example 1:
    Input: nums = [4,2,4,5,6]
    Output: 17
    Explanation: 
      The optimal subarray here is [2,4,5,6].

  Example 2:
    Input: nums = [5,2,1,2,5,2,1,2,5]
    Output: 8
    Explanation: 
      The optimal subarray here is [5,2,1] or [1,2,5].

  Constraints:
    1 <= nums.length <= 105
    1 <= nums[i] <= 104

  Hide Hint #1  
    The main point here is for the subarray to contain unique elements for each index. 
    Only the first subarrays starting from that index have unique elements.

  Hide Hint #2  
    This can be solved using the two pointers technique
*/

class Solution 
{
public:
  int maximumUniqueSubarray(vector<int>& nums) 
  {
    int sum = 0;
    int l = nums.size();
    priority_queue<int> pq_sum;
    unordered_map<int, int> freq;
    
    int i = 0;
    int j = 0;
    
    sum += nums[0];
    freq[nums[0]]++;
    j++;
    
    for(; i < j && j < l; ++j)
    {
      if(freq[nums[j]] > 0)
      {
        pq_sum.push(sum);
        while(freq[nums[j]] > 0)
        {
          sum -= nums[i];
          freq[nums[i]]--;
          i++;
        }
      }

      freq[nums[j]]++;
      sum += nums[j];
    }
    pq_sum.push(sum);

    return pq_sum.top();
  }
};

int main()
{
  vector<int> nums = {5,2,1,2,5,2,1,2,5};
  Solution s;
  s.maximumUniqueSubarray(nums);
}