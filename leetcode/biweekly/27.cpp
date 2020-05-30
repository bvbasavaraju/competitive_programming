/****************************************************
Date: May 30th, 2020
Successful submissions : 2
Time expiration : 1
Not Solved : 1
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/biweekly-contest-27
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
  Q: 1460. Make Two Arrays Equal by Reversing Sub-arrays
*/
class Solution1_t
{
public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) 
  {
    unordered_set<int> freq;
    for(int t : target)
    {
      freq.insert(t);
    }
    
    for(int a : arr)
    {
      if(freq.find(a) == freq.end())
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 1461. Check If a String Contains All Binary Codes of Size K
*/
class Solution2_t
{
public:
  bool hasAllCodes(string s, int k) 
  {
    int l = s.size();
    
    unordered_set<string> strs;
    
    string temp = "";
    for(int i = 0; i < k; ++i)
    {
      temp += s[i];
    }
    strs.insert(temp);
    
    for(int i = k; i < l; ++i)
    {
      temp += s[i];
      temp.erase(temp.begin());
      
      strs.insert(temp);
    }
    
    int total_combinations = 1 << k;
    
    return strs.size() == total_combinations ? true : false;
  }
};

/*
  Q: 1462. Course Schedule IV - Time limit exceeded. But nothing shown in the more option
*/

class Solution3_t
{
private:
  map< pair<int, int>, bool> pm;
  bool isDependent(int course, int req, vector<bool>& visited, unordered_map<int, vector<int> >& deps)
  {
    pair<int, int> p = std::make_pair(course, req);
    if(pm.find(p) != pm.end())
    {
      return pm[p]; 
    }
    
    visited[course] = true;
    
    if(visited[req] == true)
    {
      visited[course] = false;
      
      pm[p] = true;
      return true;
    }
    
    for(auto d : deps[course])
    {
      if(isDependent(d, req, visited, deps))
      {
        visited[course] = false;
        
        pm[p] = true;
        return true;
      }
    }
    
    visited[course] = false;
    
    pm[p] = false;
    return false;
  }
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) 
  {
    unordered_map<int, vector<int>> deps;
    for(auto t : p)
    {
      deps[t[1]].push_back(t[0]);
    }
    
    vector<bool> ans;
    vector<bool> visited(n, false);
    for(auto t : q)
    {
      ans.push_back(isDependent(t[1], t[0], visited, deps));
    }
    
    return ans;
  }
};

/*
  Q: 1463. Cherry Pickup II
*/
class Solution4_t
{
public:
  int cherryPickup(vector<vector<int>>& grid) 
  {
  }
};