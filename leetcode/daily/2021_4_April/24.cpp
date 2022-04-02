/****************************************************
Date: April 24th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/596/week-4-april-22nd-april-28th/3717/
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
  Q: Critical Connections in a Network

  There are n servers numbered from 0 to n-1 connected by undirected server-to-server 
  connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. 
  Any server can reach any other server directly or indirectly through the network.

  A critical connection is a connection that, if removed, will make some server unable to reach some other server.

  Return all critical connections in the network in any order.

  Example 1:
    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: 
      [[3,1]] is also accepted.

  Constraints:
    1 <= n <= 10^5
    n-1 <= connections.length <= 10^5
    connections[i][0] != connections[i][1]
    There are no repeated connections.

  Hide Hint #1  
    Use Tarjan's algorithm.
*/

class Solution 
{
private:
  vector<int> discoveryTime;
  vector<int> lowestDiscoveryTime;
  
  void findCriticalBridge(int element, int parent, vector< vector<int> >& adj, vector<bool>& visited, vector< vector<int> >& ans)
  {
    static int time = 1;
    
    visited[element] = true;
    
    discoveryTime[element] = time;
    lowestDiscoveryTime[element] = time;
    
    time++;
    
    for(int& e : adj[element])
    {
      if(!visited[e])
      {
        findCriticalBridge(e, element, adj, visited, ans);
        
        lowestDiscoveryTime[element] = min(lowestDiscoveryTime[element], lowestDiscoveryTime[e]);
        if(lowestDiscoveryTime[e] > discoveryTime[element])
        {
          ans.push_back({element, e});
        }
      }
      else if(e != parent)
      {
        lowestDiscoveryTime[element] = min(lowestDiscoveryTime[element], lowestDiscoveryTime[e]);
      }
    }
  }
    
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
  {
    vector< vector<int> > adj(n);
    for(vector<int>& conn : connections)
    {
      adj[conn[0]].push_back(conn[1]);
      adj[conn[1]].push_back(conn[0]);
    }
    
    
    discoveryTime.resize(n, INT_MAX);
    lowestDiscoveryTime.resize(n, INT_MAX);
    
    vector<bool> visited(n, false);
    vector< vector<int> > ans;
    for(int i = 0; i < n; ++i)
    {
      if(!visited[i])
      {
        findCriticalBridge(i, -1, adj, visited, ans);
      }
    }
    
    return ans;
  }
};