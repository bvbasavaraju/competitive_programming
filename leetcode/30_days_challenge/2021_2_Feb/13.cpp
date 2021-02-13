/****************************************************
Date: Feb 12th

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
  Q: Shortest Path in Binary Matrix

  In an N by N square grid, each cell is either empty (0) or blocked (1).

  A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

  Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
    C_1 is at location (0, 0) (ie. has value grid[0][0])
    C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
    If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
    
  Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

  Example 1:
    Input: [[0,1],[1,0]]
    Output: 2

  Example 2:
    Input: [[0,0,0],[1,1,0],[1,1,0]]
    Output: 4

  Note:
    1 <= grid.length == grid[0].length <= 100
    grid[r][c] is 0 or 1
    
  Hide Hint #1  
    Do a breadth first search to find the shortest path.
*/

class Solution 
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
  {
    int l = grid.size();
    
    if(grid[0][0] || grid[l-1][l-1])
    {
      return -1;
    }
    
    vector< vector<int> > dir = {{-1,-1}, {-1, 0}, {-1, 1},
                                 {0,-1}, {0, 1},
                                 {1, -1}, {1, 0}, {1, 1}};
    
    queue<vector<int>> points;
    
    points.push({0,0,1});
    
    while(!points.empty())
    {
      vector<int> data = points.front();
      points.pop();
      
      if(data[0] == l-1 && data[1] == l-1)
      {
        return data[2];
      }
      
      for(vector<int> d : dir)
      {
        int x = data[0] + d[0];
        int y = data[1] + d[1];
        
        if(x >= 0 && y >= 0 && x < l && y < l && grid[x][y] == 0)
        {
          grid[x][y] = 1;
          points.push({x, y, data[2]+1});
        }
      }
    }
    
    return -1;
  }
};
