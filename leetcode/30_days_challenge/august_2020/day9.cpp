/****************************************************
Date: July 9th

link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
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
#include <set>

using namespace std;

/*
  Q: Rotting Oranges

  In a given grid, each cell can have one of three values:
    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.
    Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

  Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
  Example 1:
    Input: [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

  Example 2:
    Input: [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

  Example 3:
    Input: [[0,2]]
    Output: 0
    Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

  Note:
    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.
*/

class Solution 
{
private:
  void processRotting(vector<vector<int>>& grid, queue<pair<int, int>>& g, int r, int c, int& count)
  {
    vector<vector<int>> dir = {{0,-1}, {-1,0}, {1,0}, {0,1}};
    while(!g.empty())
    {
      count++;
      for(int i = g.size(); i > 0; --i)
      {
        pair<int, int> p = g.front();
        g.pop();
        
        for(auto d : dir)
        {
          int x = p.first + d[0];
          int y = p.second + d[1];
          
          if(x < 0 || y < 0 || x >= r || y >= c || grid[x][y] != 1)
          {
            continue;
          }
          
          grid[x][y] = 2;
          g.push(make_pair(x,y));
        }
      }
    }
  }
  
public:
  int orangesRotting(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    queue<pair<int, int>> g;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(grid[i][j] == 2)
        {
          g.push(make_pair(i, j));
        }
      }
    }
    
    int ans = 0;
    processRotting(grid, g, r, c, ans);
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(grid[i][j] == 1)
        {
          ans = -1;
          break;
        }
      }
    }
    
    return ans <= 0 ? ans : ans-1;
  }
};