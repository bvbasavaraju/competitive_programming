#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
  bool isAllowed(vector<string> grid, int row, int col, int n)
  {
    if(row == 0)
    {
      return true;
    }
    
    if((col < n-1 && grid[row-1][col+1] == 'Q') 
       || (col > 0 && grid[row-1][col-1] == 'Q')
       || (grid[row-1][col] == 'Q'))
     {
       return false;
     }
    
    for(int i = row-1; i >= 0; --i)
    {
      if(grid[i][col] == 'Q')
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
        // if(solve(r+1, n, grid, ans))
        // {
        //   return true;
        // }
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