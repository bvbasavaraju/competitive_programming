/****************************************************
Date: April 18th, 2021
Successful submissions : 1
Time expiration : 3
Not Solved : 0
Wrong Answer/ Partial result : 0

Note: all solved for the first time. with 3 TLE. out of which 1 resolved using memoization and 1 after looking at discussion

link: https://leetcode.com/contest/weekly-contest-237
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
  Q: 1832. Check if the Sentence Is Pangram
*/
class Solution1_t
{
public:
  bool checkIfPangram(string sentence) 
  {
    vector<int> letters(26, 0);
    
    for(int ch : sentence)
    {
      letters[ch-'a']++;
    }
    
    for(int l : letters)
    {
      if(l == 0)
      {
        return false;
      }
    }
    
    return true;
  }
};

/*
  Q: 1833. Maximum Ice Cream Bars - solved using memoization
*/
class Solution2_t
{
private:
  unordered_map<int, int> cost;
  int getMax(const vector<int>& costs, int p, int coins)
  {
    if(p >= costs.size() || (costs[p] > coins))
    {
      return 0;
    }
    
    if(cost.count(p) > 0)
    {
      return cost[p];
    }
    
    int maxi = max(1+getMax(costs, p+1, coins - costs[p]), getMax(costs, p+1, coins));
    cost[p] = maxi;
    
    return maxi;
  }
    
public:
  int maxIceCream(vector<int>& costs, int coins) 
  {
    sort(costs.begin(), costs.end());
    
    return getMax(costs, 0, coins);
  }
};

/*
  Q: 1834. Single-Threaded CPU - TLE
*/
class Solution3_t
{
private:
  struct myCompare
  {
    bool operator()(const vector<int> p1, const vector<int> p2)
    {      
      return ((p1[1] > p2[1]) || (p1[1] == p2[1] && p1[2] > p2[2]));
    }
  };
  
public:
  vector<int> getOrder(vector<vector<int>>& tasks) 
  {    
    priority_queue< vector<int>, vector< vector<int> >, myCompare > available;
    
    unordered_map<int, vector<int> > t_pos;
    
    int l = tasks.size();
    int max_time = 0;
    int min_time = INT_MAX;
    for(int i = 0; i < l; ++i)
    {
      t_pos[tasks[i][0]].push_back(i);
      
      max_time = max(tasks[i][0], max_time);
      min_time = min(tasks[i][0], min_time);
    }
    
    vector<int> ans;
    int et = 0;
    for(int i = min_time; i <= max_time; ++i)
    {
      if(t_pos.count(i) > 0)
      {
        vector<int>& pos = t_pos[i];
        for(int& p : pos)
        {
          available.push({tasks[p][0], tasks[p][1], p});
        }
      }
      
      if((i >= et) && !available.empty() && (available.top()[0] <= i))
      {
        et = i + available.top()[1];
        ans.push_back(available.top()[2]);
        available.pop();
      }
    }
    
    while(!available.empty())
    {
      ans.push_back(available.top()[2]);
      available.pop();
    }
    
    return ans;
  }
};

/*
  Q: 1835. Find XOR Sum of All Pairs Bitwise AND - TLE solved after looking at discussion
*/
class Solution4_t
{
public:
  int getXORSum(vector<int>& arr1, vector<int>& arr2) 
  {
    int l1 = arr1.size();
    int l2 = arr2.size();
    
    int a1 = 0;
    for(int a : arr1)
    {
      a1 ^= a;
    }
    
    int ans = 0;
    
    for(int a : arr2)
    {
      ans = ans ^ (a1 & a);
    }
    
    //TLE
    // int ans = 0;
    // for(int i = 0; i < l1; ++i)
    // {
    //   for(int j = 0; j < l2; ++j)
    //   {
    //     ans = ans ^ (arr1[i] & arr2[j]);
    //   }
    // }
    
    return ans;
  }
};