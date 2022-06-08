#include<bits/stdc++.h>

using namespace std;

vector<int> Solution::getRow(int A) 
{
    vector<vector<int>> grid(A+1, vector<int>(A+1, 0));

    for(int i = 0; i <= A; ++i)
    {
        for(int j = 0; j <= A; ++j)
        {
            if(i == 0 || j == 0)
            {
                grid[i][j] = 1;
                continue;
            }

            grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }

    vector<int> ans;
    for(int i = A, j = 0; i >= 0 && j <= A ; --i, ++j)
    {
        ans.push_back(grid[i][j]);
    }

    return ans;
}
