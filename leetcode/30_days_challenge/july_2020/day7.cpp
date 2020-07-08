/****************************************************
Date: July 7th

link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/
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
  Q: Island Perimeter

  You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
  Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
  and there is exactly one island (i.e., one or more connected land cells).

  The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
  One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

  Example:

    Input:
    [[0,1,0,0],
    [1,1,1,0],
    [0,1,0,0],
    [1,1,0,0]]

    Output: 16
*/

class Solution 
{
public:
  int islandPerimeter(vector<vector<int>>& grid) 
  {
    int r = grid.size();
    int c = grid[0].size();
    
    int ans = 0;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(!grid[i][j])
        {
          continue;
        }

        if(i == 0 || grid[i-1][j] == 0)
        {
          ans++;
        }
        if(j == 0 || grid[i][j-1] == 0)
        {
          ans++;
        }
        if(i == r-1 || grid[i+1][j] == 0)
        {
          ans++;
        }
        if(j == c-1 || grid[i][j+1] == 0)
        {
          ans++;
        }
      }
    }

    return ans;
  }
};