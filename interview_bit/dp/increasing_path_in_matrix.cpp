#include<bits/stdc++.h>
using namespace std;

int Solution::solve(vector<vector<int> > &A) 
{
    int row = A.size();
    int col = A[0].size();

    vector< vector<int> > pathCount(row, vector<int>(col, 0));

    for(int i = 0; i < row; ++i)
    {
        for(int  j = 0; j < col; ++j)
        {
            if(i == 0 && j == 0)
            {
                pathCount[i][j] = 1;
                continue;
            }

            if(i == 0)
            {
                int prevPathCount = pathCount[i][j-1];
                pathCount[i][j] = ((A[i][j] > A[i][j-1]) &&  (prevPathCount >= 0)) ? prevPathCount + 1 : -1;

                continue;
            }

            if(j == 0)
            {
                int prevPathCount = pathCount[i-1][j];
                pathCount[i][j] = ((A[i][j] > A[i-1][j]) &&  (prevPathCount >= 0)) ? prevPathCount + 1 : -1;

                continue;
            }

            if(pathCount[i-1][j] < 0 && pathCount[i][j-1] < 0)
            {
                pathCount[i][j] = -1;
            }
            else if(pathCount[i-1][j] < 0)
            {
                int prevPathCount = pathCount[i][j-1];
                pathCount[i][j] = A[i][j] > A[i][j-1] ? 1 + prevPathCount : -1;
            }
            else if(pathCount[i][j-1] < 0)
            {
                int prevPathCount = pathCount[i-1][j];
                pathCount[i][j] = A[i][j] > A[i-1][j] ? 1 + prevPathCount : -1;
            }
            else
            {
                if(pathCount[i-1][j] > pathCount[i][j-1])
                {
                    pathCount[i][j] = A[i][j] > A[i-1][j] ? 1 + pathCount[i-1][j] : (A[i][j] > A[i][j-1] ? 1+pathCount[i][j-1] : -1);
                }
                else if(pathCount[i][j-1] > pathCount[i-1][j])
                {
                    pathCount[i][j] = A[i][j] > A[i][j-1] ? 1 + pathCount[i][j-1] : (A[i][j] > A[i-1][j] ? 1+pathCount[i-1][j] : -1);
                }
                else
                {
                    pathCount[i][j] = A[i][j] > A[i][j-1] ? 1 + pathCount[i][j-1] : (A[i][j] > A[i-1][j] ? 1+pathCount[i-1][j] : -1);
                }
            }
        }
    }

    return pathCount[row-1][col-1];
}
