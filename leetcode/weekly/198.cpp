/****************************************************
Date: July 19th, 2020
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
  Q: 1518. Water Bottles
*/
class Solution 
{
public:
  int numWaterBottles(int numBottles, int numExchange) 
  {
    int ans = numBottles;
    
    while(numBottles > 0)
    {
      int full = numBottles / numExchange;
      int empty = numBottles % numExchange;
      
      numBottles = full + empty;
      
      ans += full;
      if(numBottles < numExchange)
      {
        break;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1519. Number of Nodes in the Sub-Tree With the Same Label
*/

class Solution 
{
  int getCount(vector<int> e, unordered_map<int, vector<int>>& m, string& labels, char letter)
  {    
    int ans = 0;
    for(auto e_ : e)
    {
      if(labels[e_] == letter)
      {
        ans++;
      }
      
      ans += getCount(m[e_], m, labels, letter);
    }
    
    return ans;
  }
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
  {
    unordered_map<int, vector<int>> m;
    for(vector<int> e : edges)
    {
      m[e[0]].push_back(e[1]);
    }
    
    vector<int> ans;
    for(int i = 0; i < n; ++i)
    {
      ans.push_back(getCount(m[i], m, labels, labels[i]) + 1);
    }
    
    return ans;
  }
};

/*
  Q: 1520. Maximum Number of Non-Overlapping Substrings
*/
class Solution 
{
public:
  vector<string> maxNumOfSubstrings(string s) 
  {
      
  }
};

/*
  Q: 1521. Find a Value of a Mysterious Function Closest to Target
*/
class Solution 
{
public:
  int closestToTarget(vector<int>& arr, int target) 
  {
    
  }
};