/****************************************************
Date: Feb 14th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/
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
  Q: Is Graph Bipartite?

  Given an undirected graph, return true if and only if it is bipartite.
  Recall that a graph is bipartite if we can split its set of nodes into two independent subsets A and B, 
  such that every edge in the graph has one node in A and another node in B.

  The graph is given in the following form: graph[i] is a list of indexes j for which 
  the edge between nodes i and j exists. Each node is an integer between 0 and graph.length - 1. 
  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

  Example 1:
    Input: graph = [[1,3],[0,2],[1,3],[0,2]]
    Output: true
    Explanation: 
      We can divide the vertices into two groups: {0, 2} and {1, 3}.

  Example 2:
    Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
    Output: false
    Explanation: 
      We cannot find a way to divide the set of nodes into two independent subsets.

  Constraints:
    1 <= graph.length <= 100
    0 <= graph[i].length < 100
    0 <= graph[i][j] <= graph.length - 1
    graph[i][j] != i
    All the values of graph[i] are unique.
    The graph is guaranteed to be undirected. 
*/
class Solution 
{  
public:
  bool isBipartite(vector<vector<int>>& graph) 
  {
    int l = graph.size();
    
    vector<int> color(l, 0);
    
    for(int i = 0; i < l; ++i)
    {
      if(color[i] != 0)
      {
        continue;
      }
      
      queue<int> nodes;
      nodes.push(i);
      
      while(!nodes.empty())
      {
        int node = nodes.front();
        nodes.pop();
        
        if(color[node] == 0)
        {
          color[node] = 1;
        }
        
        for(int adj : graph[node])
        {
          if(color[adj] == 0)
          {
            color[adj] = color[node] * -1;
            nodes.push(adj);
          }
          else if(color[adj] == color[node])
          {
            return false;
          }
        }
      }
    }
    
    return true;
  }
};