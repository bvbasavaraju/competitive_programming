#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  void getMin(vector<int>& cost, map<int, vector<int>>& valPos)
  {
    int i = 0;
    for(int c : cost)
    {
      valPos[c].push_back(i);
      i++;
    }
  }
  
  int getMinInCol(vector<vector<int>>& cost, int c, int r)
  {
    int ans = INT_MAX;
    for(int i = 0; i < r; ++i)
    {
      ans = min(ans, cost[i][c]);
    }
    
    return ans;
  }
public:
  int connectTwoGroups(vector<vector<int>>& cost) 
  {
    unordered_map<int, int> g1;
    unordered_map<int, int> g2;
    
    int ans = 0;
    int r = cost.size();
    int c = cost[0].size();
    
    for(int i = 0; i < r; ++i)
    {
      map<int, vector<int>> valPos;
      getMin(cost[i], valPos);
      
      bool processed = false;
      for(auto it = valPos.begin(); it != valPos.end() && !processed; ++it)
      {
        for(int j : it->second)
        {
          if(g2.find(j) == g2.end())
          {
            ans += it->first;
            g1[i] = it->first;
            g2[j] = it->first;
            processed = true;
            break;
          }
        }
      }
      
      if(!processed)
      {
        auto it = valPos.begin();
        ans += it->first;
        int j = it->second[0];
        
        g1[i] = it->first;
        g2[j] = it->first;
      }      
    }
    
    for(int j = 0; j < c; ++j)
    {
      if(g2.find(j) == g2.end())
      {
        ans += getMinInCol(cost, j, r);
      }
    }
    
    return ans;
  }
};

int main()
{
  vector<vector<int>> vals = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  Solution s;
  s.connectTwoGroups(vals);

  return 0;
}