#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution 
{
private:
    bool isValid(vector< vector<char> >& board, int r, int c)
  {
    //check row
    {
      vector<int> freq(10, 0);
      vector<char>& row = board[r];
      for(int i = 0; i < 9; ++i)
      {
        if((row[i] != '.') && (++freq[row[i] - '0'] > 1))
        {
          return false;
        }
      }
    }
    
    //check column
    {
      vector<int> freq(10, 0);
      for(int i = 0; i < 9; ++i)
      {
        if((board[i][c] != '.') && (++freq[board[i][c] - '0'] > 1))
        {
          return false;
        }
      }
    }
    
    //check box
    {
      int r_start = (r < 3) ? 0 : ((r < 6) ? 3 : 6);
      int c_start = (c < 3) ? 0 : ((c < 6) ? 3 : 6);
      
      vector<int> freq(10, 0);
      for(int i = r_start; i < r_start+3; ++i)
      {
        for(int j = c_start; j < c_start + 3; ++j)
        {
          if((board[i][j] != '.') && (++freq[board[i][j] - '0'] > 1))
          {
            return false;
          }
        }
      }
    }
    
    return true;
  }
  
  bool solve(vector< vector<char> >& board, int r, int c)
  {  
    if(r >= 9)
    {
      return true;
    }
    
    if(c >= 9)
    {
      return solve(board, r+1, 0);
    }
    
    if (board[r][c] != '.')
    {
      return solve(board, r, c+1);
    }
    
    for(int val = 1; val < 10; ++val)
    {
      board[r][c] = val + '0';

      if(isValid(board, r, c))
      {
        if(solve(board, r, c+1))
        {
          return true;
        }
      }
    }
    
    board[r][c] = '.';
    return false;
  }
  
public:
  void solveSudoku(vector<vector<char>>& board) 
  {
    solve(board, 0, 0);
  }
};