/*
Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Ex:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

Link: https://leetcode.com/problems/minimum-path-sum/
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution_t
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int retVal = 0;
        int rowCount = grid.size();
        for (int i = 0; i < rowCount; i++)
        {
            int colCount = grid[i].size();
            for (int j = 0; j < colCount; j++)
            {
                if (i == 0)
                {
                    if (j > 0)
                    {
                        grid[i][j] += grid[i][j - 1];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        grid[i][j] += grid[i - 1][j];
                    }
                    else
                    {
                        int currVal = grid[i][j];
                        grid[i][j] = min((grid[i - 1][j] + currVal), (grid[i][j - 1] + currVal));
                    }
                }

                retVal = grid[i][j];
            }
        }

        return retVal;
    }
};