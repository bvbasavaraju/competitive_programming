#include <bits/stdc++.h>
using namespace std;

bool canPlaceQueen(const vector<string>& grid, int row, int col)
{
    //check prev rows
    for(int i = row-1; i >= 0; --i)
    {
        if(grid[i][col] == 'Q')
        {
            return false;
        }
    }

    //check prev cols
    for(int i = col-1; i >= 0; --i)
    {
        if(grid[row][i] == 'Q')
        {
            return false;
        }
    }

    //check left diag
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
    {
        if(grid[i][j] == 'Q')
        {
            return false;
        }
    }

    //check right diag
    for(int i = row-1, j = col+1; i >= 0 && j < grid.size(); --i, ++j)
    {
        if(grid[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void getAllPossibleCombinations(vector<string> grid, int row, vector<vector<string>>& ans)
{
    if(row == grid.size())
    {
        ans.push_back(grid);
        return;
    }

    for(int col = 0; col < grid.size(); ++col)
    {
        if(canPlaceQueen(grid, row, col))
        {
            grid[row][col] = 'Q';
            getAllPossibleCombinations(grid, row+1, ans);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) 
{
    string row = "";
    for(int i = 0; i < A; ++i)
    {
        row += ".";
    }

    vector<string> grid;
    for(int i = 0; i < A; ++i)
    {
        grid.push_back(row);
    }

    vector<vector<string>> ans;
    getAllPossibleCombinations(grid, 0, ans);

    return ans;
}
