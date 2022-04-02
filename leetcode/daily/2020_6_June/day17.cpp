/****************************************************
Date: June 17th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/
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
  Q: Surrounded Regions

  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
  A region is captured by flipping all 'O's into 'X's in that surrounded region.

  Example:

    X X X X
    X O O X
    X X O X
    X O X X
    
  After running your function, the board should be:

    X X X X
    X X X X
    X X X X
    X O X X
 
  Explanation:
  Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
  Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
  Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution 
{
private:
  int r;
  int c;
  void visit(vector<vector<char>>& b, int i, int j)
  {
    if(i < 0 || j < 0 || i >= r || j >= c || b[i][j] != 'O')
    {
      return;
    }
    
    b[i][j] = 1;
    
    visit(b, i+1, j);
    visit(b, i-1, j);
    visit(b, i, j+1);
    visit(b, i, j-1);
  }
  
public:
  void solve(vector<vector<char>>& board) 
  {
    r = board.size();
    if(r <= 0)
    {
      return;
    }
    c = board[0].size();
    
    for(int i = 0; i < c; ++i)
    {
      if(board[0][i] == 'O')
      {
        visit(board, 0, i);
      }
      
      if(board[r-1][i] == 'O')
      {
        visit(board, r-1, i);
      }
      
    }
    
    for(int i = 0; i < r; ++i)
    {
      if(board[i][0] == 'O')
      {
        visit(board, i, 0);
      }
      
      if(board[i][c-1] == 'O')
      {
        visit(board, i, c-1);
      }
    }
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(board[i][j] == 'O')
          board[i][j] = 'X';
        else if(board[i][j] == 1)
          board[i][j] = 'O';
      }
    }
  }
};