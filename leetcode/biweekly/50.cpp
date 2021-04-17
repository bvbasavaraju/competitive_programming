/****************************************************
Date: April 17th, 2021
Successful submissions : 3
Time expiration : 1
Not Solved : 0
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-50
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
 * Q: 1827. Minimum Operations to Make the Array Increasing
 */
class Solution1_t
{
public:
  int minOperations(vector<int>& nums) 
  {
    int ans = 0;
   
    int l = nums.size();
    for(int i = 1; i < l; ++i)
    {
      if(nums[i] <= nums[i-1])
      {
        int delta = abs(nums[i] - nums[i-1]) + 1;
        ans += delta;
        nums[i] += delta;
      }
    }
    
    return ans;
  }
};

/*
 * Q: 1828. Queries on Number of Points Inside a Circle
 */
class Solution2_t
{
private:
  bool isInCircle(int x1, int y1, int x2, int y2, int r_sq)
  {
    int dist_sq = ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1));
    
    return dist_sq <= r_sq;
  }
  
public:
  vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
  {
    vector<int> ans;
    
    for(vector<int>& q : queries)
    {
      int count = 0;
      int r_sq = q[2] * q[2];
      for(vector<int>& p : points)
      {
        if(isInCircle(p[0], p[1], q[0], q[1], r_sq))
        {
          count++;
        }
      }
      
      ans.push_back(count);
    }
    
    return ans;
  }
};

/*
 * Q: 1829. Maximum XOR for Each Query
 */
class Solution3_t
{
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
  {
    int l = nums.size();
    
    int xorVal = 0;
    for(int n : nums)
    {
      xorVal ^= n;
    }
    
    int maxVal = 1;
    while(maximumBit > 0)
    {
      maxVal <<= 1;
      maximumBit--;
    }
    
    maxVal -= 1;
    
    vector<int> ans(l);
    for(int i = 0; i < l; ++i)
    {
      ans[i] = xorVal ^ maxVal;
      
      xorVal ^= nums.back();
      nums.pop_back();
    }
    
    return ans;
  }
};

/*
 * Q: 1830. Minimum Number of Operations to Make String Sorted - time limit exceeded. need to fix
 */
class Solution4_t
{
public:
  int makeStringSorted(string s) 
  {
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    
    static const int MOD = 1e9 + 7;
    
    int ans = 0;
    int l = s.size();
    while(s != sorted_s)
    {
      int large_i = 0;
      for(int i = 1; i < l; ++i)
      {
        if(s[i] < s[i-1])
        {
          large_i = i;
        }
      }
      
      int large_j = large_i;
      for(int j = large_i; j < l; ++j)
      {
        for(int k = large_i; k <= j; ++k)
        {
          if(s[k] < s[large_i-1])
          {
            large_j = j;
          }
        }
      }
      
      int ch = s[large_i - 1];
      s[large_i - 1] = s[large_j];
      s[large_j] = ch;
      
      reverse(s.begin() + large_i, s.end());
      
      ans = (ans + 1) % MOD;
    }
    
    return ans;
  }
};
