/****************************************************
Date: April 17th

link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3302/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*  
  Q: Number of Islands

  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
  An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
  You may assume all four edges of the grid are all surrounded by water.

  Example 1:
  Input:
  11110
  11010
  11000
  00000

  Output: 1

  Example 2:

  Input:
  11000
  11000
  00100
  00011

  Output: 3
*/

class Solution 
{
private:
  //Basically Erase all the Adjacent lands if Adjacent land is 1, as it has been counted already
  //Instead of erasing it can also be done with Visited flag of the grid size. 
  //By erasing you are making it you are making it constant space!
  void dfs(vector<vector<char>>& g, int r, int c, int r_size, int c_size)
  {
    g[r][c] = '0';
    if(r > 0 && g[r-1][c] == '1')
    {
      dfs(g, r-1, c, r_size, c_size);
    }
    if(r < r_size - 1 && g[r+1][c] == '1')
    {
      dfs(g, r+1, c, r_size, c_size);
    }
    if(c > 0 && g[r][c-1] == '1')
    {
      dfs(g, r, c-1, r_size, c_size);
    }
    if(c < c_size - 1 && g[r][c+1] == '1')
    {
      dfs(g, r, c+1, r_size, c_size);
    }
  }
  
public:
  int numIslands(vector<vector<char>>& g) 
  {
    int r = g.size();
    if(r <= 0)
    {
      return 0;
    }
    
    int c = g[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(g[i][j] == '1')
        {
          ans++;
          dfs(g, i, j, r, c);
        }
      }
    }
    
    return ans;
  }
};