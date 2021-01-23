#include <iostream>
#include <vector>

using namespace std;

/*
  Q: Valid Sudoku

    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
      + Each row must contain the digits 1-9 without repetition.
      + Each column must contain the digits 1-9 without repetition.
      + Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    
    Note:
      + A Sudoku board (partially filled) could be valid but is not necessarily solvable.
      + Only the filled cells need to be validated according to the mentioned rules.

    Example 1:
      Input: 
        board = 
          [["5","3",".",".","7",".",".",".","."]
          ,["6",".",".","1","9","5",".",".","."]
          ,[".","9","8",".",".",".",".","6","."]
          ,["8",".",".",".","6",".",".",".","3"]
          ,["4",".",".","8",".","3",".",".","1"]
          ,["7",".",".",".","2",".",".",".","6"]
          ,[".","6",".",".",".",".","2","8","."]
          ,[".",".",".","4","1","9",".",".","5"]
          ,[".",".",".",".","8",".",".","7","9"]]

      Output: true
    
    Example 2:
      Input: 
        board = 
          [["8","3",".",".","7",".",".",".","."]
          ,["6",".",".","1","9","5",".",".","."]
          ,[".","9","8",".",".",".",".","6","."]
          ,["8",".",".",".","6",".",".",".","3"]
          ,["4",".",".","8",".","3",".",".","1"]
          ,["7",".",".",".","2",".",".",".","6"]
          ,[".","6",".",".",".",".","2","8","."]
          ,[".",".",".","4","1","9",".",".","5"]
          ,[".",".",".",".","8",".",".","7","9"]]

      Output: false
    
    Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

    Constraints:
      + board.length == 9
      + board[i].length == 9
      + board[i][j] is a digit or '.'.
*/

class Solution 
{
private:
  bool isUnique(vector<int>& nums, char n, char ignoreChar)
  {
    if(n == ignoreChar)
    {
      return true;
    }
    
    nums[n-'0']++;
    return (nums[n-'0'] == 1);
  }
  
  bool isValid(vector<vector<char>>& board, int row, int col)
  {
    {//check row
      vector<char>& vals = board[row];
      
      vector<int> freq(10, 0);
      for(char& v : vals)
      {
        if(!isUnique(freq, v, '.'))
        {
          return false;
        }
      }
    }
    
    { //Check column
      vector<int> freq(10, 0);
      for(uint32_t i = 0U; i < 9U; ++i)
      {
        if(!isUnique(freq, board[i][col], '.'))
        {
          return false;
        }
      }
    }
    
    { //Check 3X3 grid
      int row_start = (row < 3) ? 0 : ((row < 6) ? 3 : 6);
      int col_start = (col < 3) ? 0 : ((col < 6) ? 3 : 6);
      
      vector<int> freq(10, 0);
      for(int i = row_start; i < (row_start + 3); ++i)
      {
        for(int j = col_start; j < (col_start + 3); ++j)
        {
          if(!isUnique(freq, board[i][j], '.'))
          {
            return false;
          }
        }
      }
    }
    
    return true;
  }
public:
  bool isValidSudoku(vector<vector<char>>& board) 
  {
    for(int i = 0; i < 9; ++i)
    {
      for(int j = 0; j < 9; ++j)
      {
        if(!isValid(board, i, j))
        {
          return false;
        }
      }
    }
    
    return true;
  }
};