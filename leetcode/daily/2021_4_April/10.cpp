/****************************************************
Date: April 10th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/594/week-2-april-8th-april-14th/3701/
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
  Q: Longest Increasing Path in a Matrix

  Given an m x n integers matrix, return the length of the longest increasing path in matrix.
  From each cell, you can either move in four directions: left, right, up, or down. 
  You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

  Example 1:
    Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
    Output: 4
    Explanation:
      The longest increasing path is [1, 2, 6, 9].

  Example 2:
    Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
    Output: 4
    Explanation:
      The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

  Example 3:
    Input: matrix = [[1]]
    Output: 1

  Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 200
    0 <= matrix[i][j] <= 231 - 1
*/

class Solution 
{
private:
  vector< vector<int> > mem;
  
  int calculateMaxLength(vector< vector<int> >& matrix, vector<pair<int, int> > & dir, int r, int c, int R, int C, int prev)
  {
    if(r >= R || c >= C || r < 0 || c < 0 || matrix[r][c] <= prev)
    {
      return 0;
    }
    
    if(mem[r][c] > 0)
    {
      return mem[r][c];
    }
    
    int retVal = 1;
    for(auto& d : dir)
    {
      retVal = max(retVal, 1+calculateMaxLength(matrix, dir, r+d.first, c+d.second, R, C, matrix[r][c]));
    }
    
    mem[r][c] = retVal;
    return retVal;
  }
  
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) 
  {
    int row = matrix.size();
    int col = matrix[0].size();
    
    mem.resize(row, vector<int>(col, 0));
    vector<pair<int, int> > dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    int ans = INT_MIN;
    for(int i = 0; i < row; ++i)
    {
      for(int j = 0; j < col; ++j)
      {
        ans = max(ans, calculateMaxLength(matrix, dir, i, j, row, col, -1));
      }
    }
    
    return ans;
  }
};