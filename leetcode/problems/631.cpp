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

class Solution 
{
private:
  int getCost(int p, vector<int>& cost, unordered_map<int, int>& dp)
  {    
    if(p == 0)
    {
      dp[0] = cost[0];
    }
    
    if(p == 1)
    {
      dp[1] = cost[1];
    }
    
    if(dp.count(p) == 0)
    {
      dp[p] = cost[p] + min(getCost(p-1, cost, dp), getCost(p-2, cost, dp));
    }
    
    return dp[p];
  }
  
public:
  int minCostClimbingStairs(vector<int>& cost) 
  {
    //Bottom-up approach
    int l = cost.size();
    vector<int> dp(l, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i = 2; i < l; ++i)
    {
      dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    }
    
    return min(dp[l-1], dp[l-2]);
    
//     //top - bottom approach
//     int l = cost.size();
//     unordered_map<int, int> dp;
    
//     return min(getCost(l-1, cost, dp), getCost(l-2, cost, dp));
  }
};