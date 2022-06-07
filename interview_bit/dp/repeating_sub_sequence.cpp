#include<bits/stdc++.h>
using namespace std;

int Solution::anytwo(string A) 
{
    string s1 = A;
    string s2 = A;

    int l = A.size();
    vector< vector<int> > dp(l+1, vector<int>(l+1, 0));
    for(int i = 0; i <= l; ++i)
    {
        for(int j = 0; j <= l; ++j)
        {
            if(i == 0 || j == 0)
            {
                continue;
            }

            if(s1[i-1] == s2[j-1] && i != j)
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[l][l] >= 2 ? 1 : 0;
}
