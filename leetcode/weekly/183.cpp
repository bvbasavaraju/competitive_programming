/****************************************************
Date: April 5th, 2020
Successful submissions : 0
Time expiration : 0
Not Solved : 4
Wrong Answer/ Partial result : 0

Note: Solved 2 problems after checking at discussion!!

link: https://leetcode.com/contest/weekly-contest-183
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
  Q:  1403. Minimum Subsequence in Non-Increasing Order
*/
class Solution1_t
{
public:
  vector<int> minSubsequence(vector<int>& nums) 
  {
    int t_sum = 0;
    for(int n : nums)
    {
      t_sum += n;
    }
    
    sort(nums.begin(), nums.end());
    
    vector<int> result;
    int sub_seq_sum = 0;
    int  l = nums.size();
    for(int i = l - 1; i >= 0; --i)
    {
      sub_seq_sum += nums[i];
      t_sum -= nums[i];
      
      result.push_back(nums[i]);
      
      if(sub_seq_sum > t_sum)
      {
        break;
      }
    }
    
    return result;
  }
};

/*
  Q:  1404. Number of Steps to Reduce a Number in Binary Representation to One
*/
class Solution2_t
{
public:
  int numSteps(string s) 
  {
    int ans = 0;
    int rem = 0;
    for( ; s != "1"; s.pop_back())
    {
      if(s.back() - '0' + rem == 1)
      {
        rem = 1;
        ans += 2;
      }
      else
      {
        ans += 1;
      }
    }
    
    return ans + rem;
  }
};

/*
  Q:  1405. Longest Happy String
*/
class Solution3_t
{
public:
  string longestDiverseString(int a, int b, int c) 
  {
    string s = "";
    
  }
};

/*
  Q:  1406. Stone Game III
*/
class Solution4_t
{
public:
  string stoneGameIII(vector<int>& stoneValue) 
  {
      
  }
};