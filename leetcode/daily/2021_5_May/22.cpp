/****************************************************
Date: May 22nd

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3752/
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
  Q: N-Queens

  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
  
  Given an integer n, return all distinct solutions to the n-queens puzzle.
  
  Each solution contains a distinct board configuration of the n-queens' placement, 
  where 'Q' and '.' both indicate a queen and an empty space, respectively.

  Example 1:
    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation:
      There exist two distinct solutions to the 4-queens puzzle as shown above

  Example 2:
    Input: n = 1
    Output: [["Q"]]

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
    
  void dfs(vector<string> maze, int n, int r, vector<vector<string>>& ans)
  {
    if(r >= n)
    {
      ans.push_back(maze);
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
  vector<vector<string>> solveNQueens(int n) 
  {
    vector< vector<string> > ans;
    vector<string> maze(n, string(n, '.'));
    dfs(maze, n, 0, ans);
    
    return ans;
  }
};