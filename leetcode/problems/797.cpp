#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
  void updatePath(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans)
  {
    if(node >= graph.size() /*|| (graph[node].size() == 0)*/)
    {
      if(path.back() == graph.size()-1)
      {
        ans.push_back(path);
      }
      return;
    }
    
    if(path.back() == graph.size()-1)
    {
      ans.push_back(path);
      return;
    }
    
    for(int n : graph[node])
    {
      path.push_back(n);
      updatePath(n, graph, path, ans);
      path.pop_back();
    }
  }
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
  {
    vector<int> path = {0};
    vector<vector<int>> ans;
    
    updatePath(0, graph, path, ans);
    
    return ans;
  }
};