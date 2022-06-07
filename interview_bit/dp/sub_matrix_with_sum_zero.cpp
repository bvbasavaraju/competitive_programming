#include<bits/stdc++.h>
using namespace std;

//THis should work!! For some reason one input is resulting in wrong answer!!

int Solution::solve(vector<vector<int> > &A) 
{
    int rows = A.size();
    int cols = A.size();
    
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }

            if(i == 0)
            {
                A[i][j] += A[i][j-1];
                continue;
            }

            if(j == 0)
            {
                A[i][j] += A[i-1][j];
                continue;
            }

            A[i][j] = A[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            for(int x = i; x < rows; ++x)
            {
                for(int y = j; y < cols; ++y)
                {
                    int sum = A[x][y];
                    if(i > 0)
                    {
                        sum -= A[i-1][y];
                    }

                    if(j > 0)
                    {
                        sum -= A[x][j-1];
                    }

                    if(i > 0 && j > 0)
                    {
                        sum += A[i-1][j-1];
                    }

                    if(sum == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }

    return ans;

    // vector< vector<int> > prefixSum(rows+1, vector<int>(cols+1, 0));

    // for(int i = 0; i <= rows; ++i)
    // {
    //     for(int j = 0; j <= cols; ++j)
    //     {
    //         if(i == 0 || j == 0)
    //         {
    //             continue;
    //         }

    //         prefixSum[i][j] = A[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
    //     }
    // }

    // int ans = 0;
    // for(int i = 1; i <= rows; ++i)
    // {
    //     for(int j = 1; j <= cols; ++j)
    //     {
    //         for(int x = i; x <= rows; ++x)
    //         {
    //             for(int y = j; y <= cols; ++y)
    //             {
    //                 int sum = prefixSum[x][y] - prefixSum[i-1][y] - prefixSum[x][j-1] + prefixSum[i-1][j-1];
    //                 if(sum == 0)
    //                 {
    //                     ans++;
    //                 }
    //             }
    //         }
    //     }
    // }

    // return ans;
}
