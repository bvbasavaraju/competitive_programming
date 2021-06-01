/****************************************************
Date: June 1st

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/
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
  Q: Max Area of Island

  You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
  connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid 
  are surrounded by water.

  The area of an island is the number of cells with a value 1 in the island.

  Return the maximum area of an island in grid. If there is no island, return 0.

  Example 1:
    Input: 
      grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],
              [0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
              [0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],
              [0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: 
      The answer is not 11, because the island must be connected 4-directionally.

  Example 2:
    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0

  Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    grid[i][j] is either 0 or 1.
*/

class Solution 
{
private:
  void getMaxArea(vector< vector<int> >& g, int R, int C, int r, int c, int& a)
  {
    if(r >= R || c >= C || r < 0 || c < 0 || g[r][c] <= 0)
    {
      return;
    }
    
    a+= g[r][c];
    g[r][c] = -1;
    
    //Slower!!
    // vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // for(pair<int, int>& d : dirs)
    // {
    //   getMaxArea(g, R, C, r+d.first, c+d.second, a);
    // }
    
    //Faster
    getMaxArea(g, R, C, r+1, c, a);
    getMaxArea(g, R, C, r-1, c, a);
    getMaxArea(g, R, C, r, c+1, a);
    getMaxArea(g, R, C, r, c-1, a);
  }
  
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) 
  {
    int m = grid.size();
    int n = grid[0].size();
    
    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
      for(int j = 0; j < n; ++j)
      {
        if(grid[i][j] <= 0)
        {
          continue;
        }
        
        int a = 0;
        getMaxArea(grid, m, n, i, j, a);
        ans = max(ans, a);
      }
    }
    
    return ans;
  }
};