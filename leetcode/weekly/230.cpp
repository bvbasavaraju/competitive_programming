/****************************************************
Date: Feb 30th, 2021
Successful submissions : 1
Time expiration : 0
Not Solved : 3
Wrong Answer/ Partial result : 0

link: https://leetcode.com/contest/weekly-contest-230
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
  Q: 1773. Count Items Matching a Rule
*/
class Solution 
{
public:
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
  {
    int ans = 0;
    
    int p = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
    for(vector<string>& item : items)
    {
      if(item[p] == ruleValue)
      {
        ans++;
      }
    }
    
    return ans;
  }
};

/*
  Q: 1774. Closest Dessert Cost - solved after looking at discussions
*/
class Solution 
{
private:
  void getToppingsSum(vector<int>& toppingCosts, int p, int sum, unordered_set<int>& sums)
  {
    if(p >= toppingCosts.size())
    {
      sums.insert(sum);
      return;
    }
    
    for(int i = 0; i < 3; ++i)
    {
      getToppingsSum(toppingCosts, p+1, sum + (toppingCosts[p] * i), sums);
    }
  }
  
public:
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
  {
    vector<int> ans(2);
    ans[0] = -100000;
    ans[1] = INT_MAX;
    
    unordered_set<int> tSum;
    getToppingsSum(toppingCosts, 0, 0, tSum);
      
    int bl = baseCosts.size();
    int tl = toppingCosts.size();
    
    for(int i = 0; i < bl; ++i)
    {
      int sum = baseCosts[i];
      if(sum == target)
      {
        return sum;
      }
      else if(sum > target)
      {
        ans[1] = min(sum, ans[1]);
        continue;
      }
      
      for(auto it = tSum.begin(); it != tSum.end(); ++it)
      {
        int t = sum + *it;
        if(t== target)
        {
          return target;
        }
        else if(t > target)
        {
          ans[1] = min(t, ans[1]);
        }
        else
        {
          ans[0] = max(t, ans[0]);
        }
      }
    }
    
    return target - ans[0] <= ans[1] - target ? ans[0] : ans[1];
  }
};

/*
  Q: 1775. Equal Sum Arrays With Minimum Number of Operations
*/
class Solution 
{
public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) 
  {
      
  }
};

/*
  Q: 1776. Car Fleet II
*/
class Solution 
{
public:
  vector<double> getCollisionTimes(vector<vector<int>>& cars) 
  {
      
  }
};