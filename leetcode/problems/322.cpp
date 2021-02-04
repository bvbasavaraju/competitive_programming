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
  Q: 322. Coin Change
*/

class Solution 
{
public:
  int coinChange(vector<int>& coins, int amount) 
  {
    if(amount == 0)
    {
      return 0;
    }
    
    int l = coins.size();
    
    vector< vector<int> > dp(l, vector<int>(amount+1, -1));
    
    for(int i = 0; i < l; ++i)
    {
      for(int j = 0; j <= amount; ++j)
      {
        if(j == 0)
        {
          dp[i][j] = 0;
          continue;
        }
        
        int excluding = (i == 0) || (dp[i-1][j] == -1) ? INT_MAX : dp[i-1][j];
        int including = (j < coins[i]) || (dp[i][j-coins[i]] == -1) ? INT_MAX - 1 : dp[i][j-coins[i]];
        
        dp[i][j] = min(excluding, 1 + including);
        if(dp[i][j] == INT_MAX)
        {
          dp[i][j] = -1;
        }
      }
    }
    
    return  dp[l-1][amount];
  }
};