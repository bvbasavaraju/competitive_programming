#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
  bool isAllowed(vector<string> grid, int row, int col, int n)
  {
    //check row
    for(int i = col; i >= 0; --i)
    {
      if(grid[row][i] == 'Q')
      {
        return false;
      }
    }

    //check col
    for(int i = row; i >= 0; --i)
    {
      if(grid[i][col] == 'Q')
      {
        return false;
      }
    }

    //check left diag
    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
      if(grid[i][j] == 'Q')
      {
        return false;
      }
    }

    //check right diag
    for(int i = row, j = col; i >= 0 && j < n; --i, ++j)
    {
      if(grid[i][j] == 'Q')
      {
        return false;
      }
    }
    
    return true;
  }
  
  void solve(int r, int n, vector<string>& grid, vector<vector<string>>& ans)
  {
    if(r > n)
    {
      ans.push_back(grid);
      return;
    }
    
    for(int i = 0; i < n; ++i)
    {
      if(isAllowed(grid, r, i, n))
      {
        grid[r][i] = 'Q';
        solve(r+1, n, grid, ans);
        grid[r][i] = '.';
      }
    }
    
    return;
  }
  
public:
  vector<vector<string>> solveNQueens(int n) 
  {
    string row = "";
    for(int i = 0; i < n; ++i)
    {
      row += '.';
    }
    
    vector<string> grid;
    for(int i = 0; i < n; ++i)
    {
      grid.push_back(row);
    }
    
    vector<vector<string>> ans;
    solve(0, n, grid, ans);
    
    return ans;
  }
};

int main()
{
  Solution s;
  s.solveNQueens(4);

  return 0;
}