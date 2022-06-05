#include <bits/stdc++.h>
using namespace std;

int Solution::minDistance(string A, string B) 
{
    int al = A.size();
    int bl = B.size();

    vector<vector<int>> dp(al+1, vector<int>(bl+1, 0));
    for(int i = 0; i <= al; ++i)
    {
        for(int j = 0; j <= bl; ++j)
        {
            if(i == 0)
            {
                dp[i][j] = j;
                continue;
            }

            if(j == 0)
            {
                dp[i][j] = i;
                continue;
            }

            if(A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }

    return dp[al][bl];
}
