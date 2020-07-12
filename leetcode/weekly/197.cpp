/****************************************************
Date: July 12th, 2020
Successful submissions : 2
Time expiration : 0
Not Solved : 1
Wrong Answer/ Partial result : 1

link: https://leetcode.com/contest/weekly-contest-197
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: 1512. Number of Good Pairs
*/
class Solution1_t
{
public:
  int numIdenticalPairs(vector<int>& nums) 
  {
    int ans = 0;
    int l = nums.size();
    for(int i = 0; i < l-1; ++i)
    {
      for(int j = i + 1; j < l; ++j)
      {
        if(nums[i] == nums[j])
        {
          ans++;
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1513. Number of Substrings With Only 1s
*/
class Solution2_t
{
public:
  int numSub(string s) 
  {
    const int MOD = 1e9 + 7;
    int l = s.size();
    
    int ans = 0;
    int count = 0;
    for(int i = 0; i < l; ++i)
    {
      if(s[i] == '1')
      {
        count++;
        ans = (ans % MOD) + (count % MOD);
      }
      else
      {
        count = 0;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1514. Path with Maximum Probability - wrong ans
*/
class Solution3_t
{
  bool getProb(map<int, vector<pair<int, double> > >& conns, unordered_set<int>& visited, int start, int dest, double& prob)
  {
    if(visited.find(dest) != visited.end())
    {
      return false;
    }
    
    visited.insert(start);
    if(start == dest)
    {
      return true;
    }
        
    vector<pair<int, double> > reach = conns[start];
    
    int l = reach.size();
    for(int i = 0; i < l; ++i)
    {
      prob *= reach[i].second;
      if(getProb(conns, visited, reach[i].first, dest, prob))
      {
        return true;
      }
    }
    
    return false;
  }
  
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
  {
    map<int, vector<pair<int, double> > > connections;
    
    int l = edges.size();
    if(l != succProb.size())
    {
      return 0.000;
    }
    
    for(int i = 0; i < l; ++i)
    {
      connections[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
    }
    
    double ans = 0.0;
    
    if(connections.find(start) != connections.end())
    {
      vector<pair<int, double> > reach = connections[start];
      
      l = reach.size();
      for(int i = 0; i < l; ++i)
      {
        unordered_set<int> visited;
        double prob = reach[i].second;
        if(getProb(connections, visited,reach[i].first, end, prob))
        {
          ans = max(ans, prob);
        }
      }
    }
    
    return ans;
  }
};

/*
  Q: 1515. Best Position for a Service Centre
*/
class Solution4_t
{
public:
  double getMinDistSum(vector<vector<int>>& positions) 
  {
      
  }
};