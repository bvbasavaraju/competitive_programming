/****************************************************
Date: May 29th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/
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
  Q: Course Schedule
  There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
  Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
  which is expressed as a pair: [0,1]

  Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

  Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0. So it is possible.

  Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0, and to take course 0 you should
                also have finished course 1. So it is impossible.

  Constraints:
    + The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
      Read more about how a graph is represented.
    + You may assume that there are no duplicate edges in the input prerequisites.
    + 1 <= numCourses <= 10^5

  Hide Hint #1  
    This problem is equivalent to finding if a cycle exists in a directed graph. 
    If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
  Hide Hint #2  
    Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
  Hide Hint #3  
    Topological sort could also be done via BFS.
*/

class Solution 
{
private:
  bool hasLoop(int source, vector<int>& neighbours, unordered_map<int, vector<int>>& vertex_edges, vector<bool>& visited)
  {
    //Initially set the visited flag to true;
    visited[source] = true;
    for(auto n : neighbours)
    {
      //If edges has been visisted already from first edge or from any other path then it means there is loop.
      if(visited[n] == true)
        return true;
      
      if(hasLoop(n, vertex_edges[n], vertex_edges, visited))
        return true;
    }
    
    //reset the visited flag
    visited[source] = false;
    return false;
  }
  
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
  {
    unordered_map<int, vector<int>> vertex_edges;
    for(auto n : prerequisites)
    {
      vertex_edges[n[1]].push_back(n[0]);
    }
    
    //Keep the visited flag
    vector<bool> visited(numCourses, false);
    for(auto it = vertex_edges.begin(); it != vertex_edges.end(); ++it)
    {
      if(hasLoop(it->first, it->second, vertex_edges, visited))
      {
        return false;
      }
    }
    
    return true;
  }
};