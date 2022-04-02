/****************************************************
Date: March 2st

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
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
  Q: Set Mismatch

  You have a set of integers s, which originally contains all the numbers from 1 to n. 
  Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
  which results in repetition of one number and loss of another number.

  You are given an integer array nums representing the data status of this set after the error.

  Find the number that occurs twice and the number that is missing and return them in the form of an array.

  Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]

  Example 2:
    Input: nums = [1,1]
    Output: [1,2]

  Constraints:
    2 <= nums.length <= 104
    1 <= nums[i] <= 104
*/
class Solution 
{
public:
  vector<int> findErrorNums(vector<int>& nums) 
  {
    vector<int> freq(nums.size()+1, 0);
    
    for(int n : nums)
    {
      freq[n]++;
    }
    
    vector<int> ans(2, 0);
    for(int i = 1; i <= nums.size(); ++i)
    {
      if(freq[i] == 2)
      {
        ans[0] = i;
      }
      else if(freq[i] == 0)
      {
        ans[1] = i;
      }
    }
    
    return ans;
  }
};