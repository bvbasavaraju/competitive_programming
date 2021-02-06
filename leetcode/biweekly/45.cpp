/****************************************************
Date: Feb 6th, 2021
Successful submissions : 3 (1 solved after understanding)
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-45
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
#include <string_view>

using namespace std;

/*
  Q: 1748. Sum of Unique Elements
*/
class Solution1_t
{
public:
  int sumOfUnique(vector<int>& nums) 
  {
    unordered_map<int, int> freq;
    for(int n : nums)
    {
      freq[n]++;
    }
    
    int ans = 0;
    for(auto p : freq)
    {
      if(p.second == 1)
      {
        ans += p.first;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1749. Maximum Absolute Sum of Any Subarray - initially, I got confused with the question. after checking the solution I realized.
*/
class Solution2_t
{
public:
  int maxAbsoluteSum(vector<int>& nums) 
  {
    int ans = 0;
    
    int sum = 0;
    for(int& n : nums)
    {
      sum = max(sum+n, n);
      ans = max(ans, sum);
      
      n *= -1;
    }
    
    sum = 0;
    for(int n: nums)
    {
      sum = max(sum+n, n);
      ans = max(ans, sum);
    }
    
    return ans;
  }
};

/*
  Q: 1750. Minimum Length of String After Deleting Similar Ends
*/
class Solution3_t
{
public:
  int minimumLength(string s) 
  {
    int l = 0;
    int h = s.size() - 1;
    
    while(l < h)
    {
      if(s[l] != s[h])
      {
        break;
      }
      
      l++;
      while(l < h && s[l-1] == s[l])
      {
        l++;
      }
      
      h--;
      while(l < h && s[h+1] == s[h])
      {
        h--;
      }
    }
    
    return h-l+1;
  }
};

/*
  Q: 1751. Maximum Number of Events That Can Be Attended II
*/
class Solution 
{
public:
  int maxValue(vector<vector<int>>& events, int k) 
  {
      
  }
};