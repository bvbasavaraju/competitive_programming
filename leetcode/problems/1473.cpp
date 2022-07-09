#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  int getMinCost(vector<int>& houses, vector<vector<int>>& cost, int target, int pos, int count, int prevColor, vector<vector<vector<int>>>& cache)
  {
    if(pos == houses.size())
    {
      return (count == target) ? 0 : INT_MAX;
    }
    
    if(pos > houses.size())
    {
      return INT_MAX;
    }
    
    if(cache[pos][count][prevColor] != -1)
    {
      return cache[pos][count][prevColor];
    }
    
    int minCost = INT_MAX;
    if(houses[pos] != 0)
    {
      if(houses[pos] == prevColor)
      {
        minCost = getMinCost(houses, cost, target, pos+1, count, houses[pos], cache);
      }
      else
      {
        minCost = getMinCost(houses, cost, target, pos+1, count+1, houses[pos], cache);
      }
    }
    else
    {
      int numColors = cost[0].size();
      for(int i = 0; i < numColors; ++i)
      {
        int cost_ = 0;
        if(i+1 == prevColor)
        {
          cost_ = getMinCost(houses, cost, target, pos+1, count, i+1, cache);
        }
        else
        {
          cost_ = getMinCost(houses, cost, target, pos+1, count+1, i+1, cache);
        }
        
        cost_ = cost_ == INT_MAX ? INT_MAX : (cost_ + cost[pos][i]);
        
        minCost = min(minCost, cost_);
      }
    }
    
    cache[pos][count][prevColor] = minCost;
    
    return minCost;
  }
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
  {
    vector<vector<vector<int>>> cache(m, vector<vector<int>>(target, vector<int>(n,-1)));
    
    int ans = getMinCost(houses, cost, target, 0, 0, 0, cache);
    
    return ans == INT_MAX ? -1 : ans;
  }
};

int main()
{
  vector<int> h = {0,0,0,0,0};
  vector<vector<int>> c = {{1,10},{10, 1}, {10, 1}, {1, 10}, {5,1}};

  Solution s;
  s.minCost(h, c, 5, 2, 3);

  return 0;
}