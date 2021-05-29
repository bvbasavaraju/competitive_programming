/****************************************************
Date: May 29th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/602/week-5-may-29th-may-31st/3760/
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
  Q: N-Queens II

  The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
  such that no two queens attack each other.

  Given an integer n, return the number of distinct solutions to the n-queens puzzle.

  Example 1:
    Input: n = 4
    Output: 2
    Explanation:
      There are two distinct solutions to the 4-queens puzzle as shown.

  Example 2:
    Input: n = 1
    Output: 1

  Constraints:
    1 <= n <= 9
*/
class Solution 
{
private:
  bool canInsert(vector<string>& maze, int r, int c, int n)
  {    
    //Check row
    for(int i = r; i >= 0; --i)
    {
      if(maze[i][c] == 'Q')
      {
        return false;
      }
    }
    
    //check col
    for(int i = c; i >= 0; --i)
    {
      if(maze[r][i] == 'Q')
      {
        return false;
      }
    }
    
    //check left diag
    for(int i = r, j = c; i >= 0 && j >= 0; --i, --j)
    {
      if(maze[i][j] == 'Q')
      {
        return false;
      }
    }
    
    //check right diag
    for(int i = r, j = c; i >= 0 && j < n; --i, ++j)
    {
      if(maze[i][j] == 'Q')
      {
        return false;
      }
    }
    
    return true;
  }
    
  void dfs(vector<string> maze, int n, int r, int& ans)
  {
    if(r >= n)
    {
      ans++;
      return;
    }
    
    for(int i = 0; i < n; ++i)
    {
      if(canInsert(maze, r, i, n))
      {
        maze[r][i] = 'Q';
        
        dfs(maze, n, r+1, ans);
        
        maze[r][i] = '.';
      }
    }
  }
public:
  int totalNQueens(int n) 
  {
    int ans = 0;
    
    vector<string> maze(n, string(n, '.'));
    dfs(maze, n, 0, ans);
    
    return ans;
  }
};