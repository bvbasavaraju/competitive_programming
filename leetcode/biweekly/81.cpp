/****************************************************
Date: June 11th, 2022
Successful submissions : 3
Time expiration : 0
Memory limit exceeded : 0
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-81
****************************************************/

#include <bits/stdc++.h>
using namespace std;

/*
  Q: 2315. Count Asterisks
*/
class Solution1_t
{
public:
  int countAsterisks(string s) 
  {
    int barCount = 0;
    int ans = 0;
    
    for(char ch : s)
    {
      if(ch == '|')
      {
        barCount++;
        continue;
      }
      
      if((barCount%2 == 0) && (ch == '*'))
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
*/
class Solution2_t
{
private:
  void getReachable(int key, long long& count, vector<bool>& visited, unordered_map<int, vector<int>>& nodeReachable)
  {
    if(visited[key] == true)
    {
      return;
    }
    
    count++;
    visited[key] = true;
    for(int adj : nodeReachable[key])
    {
      getReachable(adj, count, visited, nodeReachable);
    }
  }
  
public:
  long long countPairs(int n, vector<vector<int>>& edges) 
  {
    long long ans = 0;
    
    unordered_map<int, vector<int>> nodeReachable;
    for(vector<int> e : edges)
    {
      nodeReachable[e[0]].push_back(e[1]);
      nodeReachable[e[1]].push_back(e[0]);
    }
    
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; ++i)
    {
      long long count = 0;
      getReachable(i, count, visited, nodeReachable);
      
      ans += ((count) *  (static_cast<long long>(n)-count));
    }
    
    return ans/2;
  }
};

/*
  Q: 2317. Maximum XOR After Operations
*/
class Solution3_t
{
public:
  int maximumXOR(vector<int>& nums) 
  {
    int ans = 0;
    for(int i = 0; i < 32; ++i)
    {
      bool bitSet = false;
      for(int n : nums)
      {
        if((1 << i) & n)
        {
          bitSet = true;
        }
      }
      
      if(bitSet)
      {
        ans |= (1 << i);
      }
    }
    
    return ans;
  }
};

/*
  Q: 2318. Number of Distinct Roll Sequences
*/
class Solution4_t
{
public:
  int distinctSequences(int n) 
  {
      
  }
};