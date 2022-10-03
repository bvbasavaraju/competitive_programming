/****************************************************
Date: Sept 25th, 2022
Successful submissions : 2
Successful submissions after timeout : 0
Time expiration : 0
Memory exhausted : 0
Not Solved : 1
Incomplete Solution : 0
Wrong Answer/ Partial result : 1
Solved looking at solutions : 0

link: https://leetcode.com/contest/weekly-contest-312
****************************************************/

#include<bits/stdc++.h>
using namespace std;

/*
  Q: 2418. Sort the People
*/
class Solution1_t
{
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
  {
    priority_queue<pair<int, int>> inOrder;
    
    int l = heights.size();
    for(int i = 0; i < l; ++i)
    {
      inOrder.push({heights[i], i});
    }
    
    vector<string> ans;
    while(!inOrder.empty())
    {
      ans.push_back(names[inOrder.top().second]);
      inOrder.pop();
    }
    
    return ans;
  }
};

/*
  Q: 2419. Longest Subarray With Maximum Bitwise AND
*/
class Solution2_t
{
public:
  int longestSubarray(vector<int>& nums) 
  {
    int l = nums.size();
    
    int maxi = 0;
    int andi = 0xFFFFFFFF;
    for(int i = 0; i < l; ++i)
    {
      andi = max(andi & nums[i], nums[i]);
      maxi = max(maxi, andi);
    }
    
    int p = 0;
    int ans = 0;
    int val = 0xFFFFFFFF;
    for(int i = 0; i < l;)
    {
      if(nums[i] != maxi)
      {
        ++i;
        continue;
      }
      
      p = i;
      while((p < l) && (nums[i] & nums[p]) == maxi)
      {
        p++;
      }
      ans = max(ans, p-i);
      
      i = p;
    }
    
    return ans;
  }
};

/*
  Q: 2420. Find All Good Indices - wrong answer!! 
*/
class Solution3_t
{
public:
  vector<int> goodIndices(vector<int>& nums, int k) 
  {
    int l = nums.size();
    int start = k;
    int end = l - k;
    
    if(start >= end)
    {
      return {};
    }
    
    vector<bool> nonIncreasing(end, true);
    if(k > 1)
    {
      for(int i = 1; i < end; ++i)
      {
        bool val = nonIncreasing[i-1] && (nums[i-1] >= nums[i]);
        nonIncreasing[i] = val;
      }
    }
    
    // vector<bool> nonDecreasing(l-start-1, true);
    // if(k > 1)
    // {
    //   int p = start+1;
    //   for(int i = p+1; i < l; ++i)
    //   {
    //     bool val = nonDecreasing[i-p-1] && (nums[i-1] <= nums[i]);
    //     nonDecreasing[i] = val;
    //   }
    // }

    vector<bool> nonDecreasing(l, true);
    if(k > 1)
    {
      int p = start+1;
      for(int i = start+2; i < l; ++i, ++p)
      {
        bool val = nonDecreasing[p] && (nums[i-1] <= nums[i]);
        nonDecreasing[i] = val;
      }
    }
    
    vector<int> ans;
    bool before = true;
    bool after = true;
    for(int i = start; i < end; ++i)
    {
      if(nonIncreasing[i-1] && nonDecreasing[i+k-start-1])
      {
        ans.push_back(i);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2421. Number of Good Paths - not solved!
*/
class Solution4_t
{
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
  {
    vector<vector<int>> conns(vals.size());
    while(vector<int> e : edges)
    {
      conns[e[0]].push_back(e[1]);
      conns[e[1]].push_back(e[0]);
    }
    
    
  }
};
