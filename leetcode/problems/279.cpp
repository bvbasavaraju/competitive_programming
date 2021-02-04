#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: 279. Perfect Squares
*/

class Solution 
{
public:
  int numSquares(int n) 
  {
    // vector<int> dp(n+1,0);
    // for(int i=1;i<=n;i++)
    // {
    //     dp[i]=i;
    //     for(int j=1;j<=sqrt(i);j++)
    //     {
    //         dp[i]=min(dp[i],1+dp[i-j*j]);
    //     }
    // }
    // return dp[n];
    
    vector<int> squares;
    for(int i = 1; (i * i) <= n; ++i)
    {
      squares.push_back(i*i);
    }
    
    int r = squares.size();
    int c = n+1;
    
    vector< vector<int> > dp(r, vector<int>(c, 0));
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0)
        {
          dp[i][j] = j;
          continue;
        }
        
        if(j < squares[i])
        {
          dp[i][j] = dp[i-1][j];
        }
        else
        {
          dp[i][j] = min(1 + dp[i][j-squares[i]], dp[i-1][j]);
        }
      }
    }
    
    return dp[r-1][c-1];
  }
};