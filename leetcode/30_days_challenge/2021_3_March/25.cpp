/****************************************************
Date: March 25th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3681/
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
  Q: Pacific Atlantic Water Flow

  Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
  the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

  Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
  Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

  Note:
  The order of returned grid coordinates does not matter.
  Both m and n are less than 150.

  Example:
    Given the following 5x5 matrix:

      Pacific ~   ~   ~   ~   ~ 
          ~  1   2   2   3  (5) *
          ~  3   2   3  (4) (4) *
          ~  2   4  (5)  3   1  *
          ~ (6) (7)  1   4   5  *
          ~ (5)  1   1   2   4  *
              *   *   *   *   * Atlantic

  Return:
    [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

class Solution 
{
private:
  void bfs(vector<vector<int>>& m, int r, int c, queue<std::pair<int, int>>& points, vector<vector<bool>>& visited)
  {
    vector<std::pair<int, int>> dir = {{0,-1}, {0,1}, {-1,0}, {1, 0}};
    
    while(!points.empty())
    {
      std::pair<int, int> p = points.front();
      points.pop();
      
      int h = m[p.first][p.second];
      
      for(std::pair<int, int>& d: dir)
      {
        int x = d.first + p.first;
        int y = d.second + p.second;
        
        if(x >= 0 && x < r && y >=0 && y < c && m[x][y] >= h && !visited[x][y])
        {
          visited[x][y] = true;
          points.push({x,y});
        }
      }
    }
  }
  
public:
  vector< vector<int> > pacificAtlantic(vector<vector<int>>& matrix) 
  {
    vector< vector<int> > ans;
    
    int r = matrix.size();
    if(r <= 0)
    {
      return ans;
    }
    
    int c = matrix[0].size();
    if(c <= 0)
    {
      return ans;
    }
    
    vector< vector<bool> > pVisit(r, vector<bool>(c, false));
    vector< vector<bool> > aVisit(r, vector<bool>(c, false));
    
    queue<std::pair<int, int>> pPoints;
    queue<std::pair<int, int>> aPoints;
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0 ; j < c; ++j)
      {
        if((i == 0) || (j == 0))
        {
          pPoints.push({i, j});
          pVisit[i][j] = true;
        }
        if((i == r-1) || (j == c-1))
        {
          aPoints.push({i, j});
          aVisit[i][j] = true;
        }
      }
    }
    
    bfs(matrix, r, c, pPoints, pVisit);
    bfs(matrix, r, c, aPoints, aVisit);
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0 ; j < c; ++j)
      {
        if(pVisit[i][j] && aVisit[i][j])
        {
          ans.push_back({i, j});
        }
      }
    }
    
    return ans;
  }
};