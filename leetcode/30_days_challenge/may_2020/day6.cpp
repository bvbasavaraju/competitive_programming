/****************************************************
Date: May 6th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/
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
  Q: Majority Element
  Given an array of size n, find the majority element.
  The majority element is the element that appears more than ⌊ n/2 ⌋ times.

  You may assume that the array is non-empty and the majority element always exist in the array.

  Example 1:
    Input: [3,2,3]
    Output: 3

  Example 2:
    Input: [2,2,1,1,1,2,2]
    Output: 2
*/

class Solution 
{
public:
  int majorityElement(vector<int>& nums) 
  {
    int l = nums.size();
    unordered_map<int, int> freq;
    for(int n: nums)
    {
      freq[n]++;
      if(freq[n] > l/2)
      {
        return n;
      }
    }
    
    return 0;
  }
};