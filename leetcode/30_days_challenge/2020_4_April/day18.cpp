/****************************************************
Date: April 18th

link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3303/
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
  Q:  Minimum Path Sum

  Given a m x n grid filled with non-negative numbers, 
  find a path from top left to bottom right which minimizes the sum of all numbers along its path.

  Note: You can only move either down or right at any point in time.

  Example:
  Input:
  [
    [1,3,1],
    [1,5,1],
    [4,2,1]
  ]
  Output: 7

  Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution 
{
public:
  int minPathSum(vector<vector<int>>& g) 
  {
    if(g.size() == 0 && g[0].size() <= 0)
    {
      return 0;
    }
    
    int r = g.size();
    int c = g[0].size();
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0 && j == 0)
        {
          continue;
        }
        
        if(i == 0)
        {
          g[0][j] += g[0][j-1];
        }
        else if(j == 0)
        {
          g[i][0] += g[i-1][0];
        }
        else
        {
          g[i][j] += min(g[i-1][j], g[i][j-1]);
        }
      }
    }
    
    return g[r-1][c-1];
  }
};