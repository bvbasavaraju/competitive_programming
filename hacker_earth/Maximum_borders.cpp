/*
  Q: https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/maximum-border-9767e14c/
*/
#include <bits/stdc++.h>
using namespace std;

int getMaxBorders(int row, int col, vector< vector<char> >& grid)
{
  int ans = 0;
  for(int i = 0; i < row; ++i)
  {
    int count = 0;
    for(int j = 0; j < col; ++j)
    {
      if((j > 0) && (grid[i][j-1] == '.'))
      {
        ans = max(ans, count);
        count = 0;
      }

      if(grid[i][j] == '#')
      {
        count++;
      }
    }

    ans = max(ans, count);
  }

  return ans;
}

int main()
{
  int num = 0;
  std::cin >> num;
  for(int i = 0; i < num; ++i)
  {
    int row = 0;
    int col = 0;

    std::cin >> row;
    std::cin >> col;

    vector<vector<char>> grid(row, vector<char>(col, '.'));
    for(int i = 0; i < row; ++i)
    {
      for(int j = 0; j < col; ++j)
      {
        std::cin >> grid[i][j];
      }
    }

    std::cout << getMaxBorders(row, col, grid) << std::endl;
  }

  return 0;
}

