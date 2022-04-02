/****************************************************
Date: April 22th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
/*
  Q: Subarray Sum Equals K

  Given an array of integers and an integer k, you need to find the total number of 
  continuous subarrays whose sum equals to k.

  Example 1:
  Input:nums = [1,1,1], k = 2
  Output: 2

  Note:
  The length of the array is in range [1, 20,000].
  The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

  Hide Hint #1  
    Will Brute force work here? Try to optimize it.
  Hide Hint #2  
    Can we optimize it by using some extra space?
  Hide Hint #3  
    What about storing sum frequencies in a hash table? Will it be useful?
  Hide Hint #4  
    sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.
    Can we use this property to optimize it.
*/
class Solution 
{
public:
  int subarraySum(vector<int>& nums, int k) 
  {
    if(nums.empty())
    {
      return 0;
    }

    int sum = 0;
    unordered_map<int, int> sum_freq;
    sum_freq[0]++;

    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l; ++i)
    {
      sum += nums[i];

      int req = sum - k;
      ans += sum_freq[req];
      
      sum_freq[sum]++;
    }
    
    return ans;
  }
};