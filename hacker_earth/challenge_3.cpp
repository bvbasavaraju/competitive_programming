
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

//Test if this works
// void collectPathsToEnd(vector<vector<int>>& mat, int i, int j, int r, int c, vector<vector<int>> dp, vector<pair<int, int>>& path, int& prevSum, vector<pair<int, int>>& largetSumPath)
// {
//   if (i >= r || j >= c)
//   {
//     return;
//   }

//   if(mat[i][j] < 0)
//   {
//     dp[i][j] = -10;
//   }

//   if(i == r-1 && j == c-1)
//   {
//     path.push_back(make_pair(i, j));

//     int sum = 0;
//     for(auto p : path)
//     {
//       sum += mat[p.first][p.second];
//     }

//     if(sum > prevSum)
//     {
//       largetSumPath = path;
//       prevSum = sum;
//     }
//   }

//   path.push_back(make_pair(i, j));
//   collectPathsToEnd(mat, i, j+1, r, c, dp, path, prevSum, largetSumPath);
//   collectPathsToEnd(mat, i+1, j, r, c, dp, path, prevSum, largetSumPath);
//   path.pop_back();
// }

// void collectPathsToStart(vector<vector<int>>& mat, int i, int j, vector<vector<int>> dp, vector<pair<int, int>>& path, int& prevSum, vector<pair<int, int>>& largetSumPath)
// {
//   if (i < 0 || j < 0)
//   {
//     return;
//   }

//   if(dp[i][j] != -1)
//   {
//     return;
//   }

//   if(mat[i][j] < 0)
//   {
//     dp[i][j] = -10;
//   }

//   if(i == 0 && j == 0)
//   {
//     path.push_back(make_pair(i, j));

//     int sum = 0;
//     for(auto p : path)
//     {
//       sum += mat[p.first][p.second];
//     }

//     if(sum > prevSum)
//     {
//       largetSumPath = path;
//       prevSum = sum;
//     }
//   }

//   path.push_back(make_pair(i, j));
//   collectPathsToStart(mat, i, j-1, dp, path, prevSum, largetSumPath);
//   collectPathsToStart(mat, i-1, j, dp, path, prevSum, largetSumPath);
//   path.pop_back();
// }

// int collectMax(vector<vector<int>> mat)
// {
//   int ans = 0;

//   int r = mat.size();
//   if (r <= 0)
//   {
//       return 0;
//   }
//   int c = mat[0].size();

//   if(mat[r-1][c-1] < 0 || mat[0][0] < 0)
//   {
//     return 0;
//   }

//   int sum = 0;
//   vector<vector<int>> dp1(r, vector<int>(c, -1));
//   vector<pair<int, int>> path;
//   vector<pair<int, int>> largestSumPath;
//   collectPathsToEnd(mat, 0, 0, r, c, dp1, path, sum, largestSumPath);
//   if(largestSumPath.size() == 0)
//   {
//     return 0;
//   }

//   for(auto p : largestSumPath)
//   {
//     mat[p.first][p.second] = 0;
//   }
//   ans += sum;

//   sum = 0;
//   path.clear();
//   largestSumPath.clear();
//   vector<vector<int>> dp2(r, vector<int>(c, -1));
//   collectPathsToStart(mat, r-1, c-1, dp2, path, sum, largestSumPath);

//   ans += sum;

//   return ans;
// }

int collected(vector<vector<int>>& mat, int r1, int c1, int r2, int c2)
{
    if(r1 == r2 && c1 == c2)
    {
        if(mat[r1][c1] > 0)
        {
            return 1;
        }

        return 0;
    }

    int sum = 0;

    if(mat[r1][c1] > 0)
    {
        sum++;
    }
    if(mat[r2][c2] > 0)
    {
        sum++;
    }

    return sum;
}

int getMaxCollection(vector<vector<int>>& mat, vector<vector<vector<int>>>& dp, int r1, int c1, int r2, int x, int y)
{
    int c2 = (r1 + c1) - r2;

    if(r1 == x-1 && c1 == y-1 && r2 == x-1 && c2 == y-1)
    {
        return 0;
    }
    
    if(r1 >= x || r2 >= x || c1 >= y || c2 >= y)
    {
        return -10;
    }

    if(dp[r1][c1][r2] != -1)
    {
        return dp[r1][c1][r2];
    }

    int s1 = -10, s2 = -10, s3 = -10, s4 = -10;
    if(c1+1 < y && c2+1 < y && mat[r1][c1+1] != -1 && mat[r2][c2+1] != -1)
    {
        s1 = collected(mat, r1, c1+1, r2, c2+1)
        + getMaxCollection(mat, dp, r1, c1+1, r2, x, y);
    }

    if(r1+1 < x && r2+1 < x && mat[r1+1][c1] != -1 && mat[r2+1][c2] != -1)
    {
        s2 = collected(mat, r1+1, c1, r2+1, c2)
        + getMaxCollection(mat, dp, r1+1, c1, r2+1, x, y);
    }

    if(c1+1 < y && r2+1 < x && mat[r1][c1+1] != -1 && mat[r2+1][c2] != -1)
    {
        s3 = collected(mat, r1, c1+1, r2+1, c2)
        + getMaxCollection(mat, dp, r1, c1+1, r2+1, x, y);
    }

    if(r1+1 < x && c2+1 < y && mat[r1+1][c1] != -1 && mat[r2][c2+1] != -1)
    {
        s4 = collected(mat, r1+1, c1, r2, c2+1)
        + getMaxCollection(mat, dp, r1+1, c1, r2, x, y);
    }

    int m = max({s1, s2, s3, s4});
    dp[r1][c1][r2] = m;
    return m;
}

int collectMax(vector<vector<int>> mat)
{
  int ans = 0;

  int r = mat.size();
  if (r <= 0)
  {
      return 0;
  }
  int c = mat[0].size();

  if(mat[r-1][c-1] < 0 || mat[0][0] < 0)
  {
    return 0;
  }

  vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(100, -1)));

  ans += mat[r-1][c-1] + mat[0][0];
  mat[r-1][c-1] = 0;
  mat[0][0] = 0;

  ans += getMaxCollection(mat, dp, 0, 0, 0, r, c);

  ans = max(ans, 0);
  return ans;
}

int main()
{
    vector<vector<int>> m = {{0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    printf("Count = %d", collectMax(m));

    return 0;
}