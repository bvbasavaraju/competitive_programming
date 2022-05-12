#include <bits/stdc++.h>

using namespace std;

int doesMatch(const string& a, const string& b, int ap, int bp, vector< vector<int> >& dp)
{
    if((ap < 0 && bp < 0) || (ap < 0 && b[bp] == '*'))
    {
        return 1;
    }

    if(ap < 0 || bp < 0)
    {
        return 0;
    }

    if(dp[ap][bp] != -1)
    {
        return dp[ap][bp];
    }

    if(a[ap] == b[bp] || (b[bp] == '.'))
    {
        dp[ap][bp] = doesMatch(a, b, ap-1, bp-1, dp);
        return dp[ap][bp];
    }
    
    if(b[bp] == '*')
    {
        int ans1 = doesMatch(a, b, ap, bp-2, dp); // skip star
        int ans2 = 0;
        if(bp > 0 && (a[ap] == b[bp-1] || b[bp-1] == '.'))
        {
            ans2 = doesMatch(a,b,ap-1,bp, dp);
        }
        
        dp[ap][bp] = (ans1 == 1 || ans2 == 1) ? 1 : 0;
    }

    return dp[ap][bp];
}

int isMatch(const string A, const string B) 
{
    if(A.empty() || B.empty())
    {
        return 0;
    }

    int al = A.size();
    int bl = B.size();

    vector<vector<int>> dp(al, vector<int>(bl,-1));

    int ans = doesMatch(A, B, al-1, bl-1, dp);
    return ans == -1 ? 0 : ans;

    // int al = A.size();
    // int bl = B.size();

    // vector< vector<int> > dp(al+1, vector<int>(bl+1, 0));
    // for(int i = 0; i <= al; ++i)
    // {
    //     for(int j = 0; j <= bl; ++j)
    //     {
    //         if(i == 0 && j == 0)
    //         {
    //             dp[i][j] = 1;
    //             continue;
    //         }

    //         if(j == 0)
    //         {
    //             continue;
    //         }

    //         if(i == 0)
    //         {
    //             if(j > 0 && B[j-1] == '*')
    //             {
    //                 dp[i][j] = (j > 1) ? dp[i][j-2] : 0;  // ignoring the star!!
    //             }
    //             continue;
    //         }

    //         if(A[i-1] == B[j-1] || B[j-1] == '.')
    //         {
    //             dp[i][j] = dp[i-1][j-1];
    //         }
    //         else if(B[j-1] == '*')
    //         {
    //             dp[i][j] = dp[i][j-2] || ((B[j-2] == '.' || B[j-2] == A[i-1])? dp[i-1][j] : 0);
    //         }
    //     }
    // }

    // return dp[al][bl];
}


int main()
{
  string a = "efwihfioghih35i";
  string b = ".*";

  isMatch(a, b);

  return 0;
}