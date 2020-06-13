/****************************************************
Date: June 13th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/
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
  Q: Largest Divisible Subset
  Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
  Si % Sj = 0 or Sj % Si = 0.
  If there are multiple solutions, return any subset is fine.

  Example 1:
    Input: [1,2,3]
    Output: [1,2] (of course, [1,3] will also be ok)

  Example 2:
    Input: [1,2,4,8]
    Output: [1,2,4,8]
*/

class Solution 
{
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) 
  {
    sort(nums.begin(), nums.end());
    
    int l = nums.size();
    vector<int> length(l, 1); //subset length for given index
    vector<int> lastDividedPos(l, -1); //Who divided me last
    
    for(int i = 1; i < l; ++i)
    {
      for(int j = 0; j < i; ++j)
      {
        if(nums[i] % nums[j] == 0 && length[j] + 1 > length[i])
        {
          length[i] = length[j] + 1;
          lastDividedPos[i] = j;
        }
      }
    }
    
    int maxLength = 0;
    int maxPos = -1;
    for(int i = 0; i < l; ++i)
    {
      if(length[i] > maxLength)
      {
        maxLength = length[i];
        maxPos = i;
      }
    }
    
    vector<int> ans(maxLength);
    
    int i = maxLength - 1;
    while(i >= 0)
    {
      ans[i] = nums[maxPos];
      maxPos = lastDividedPos[maxPos];
      i--;
    }
    
    return ans;
  }
};

int main()
{
  // {
  //   Solution s;
  //   vector<int> v = {1,2,3};
  //   s.largestDivisibleSubset(v);
  // }
  {
    Solution s;
    vector<int> v = {1,2,3,6,9};
    s.largestDivisibleSubset(v);
  }

  return 0;
}