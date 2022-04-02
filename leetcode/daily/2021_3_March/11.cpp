/****************************************************
Date: March 11th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3665/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: Coin Change

  You are given coins of different denominations and a total amount of money amount. 
  Write a function to compute the fewest number of coins that you need to make up that amount.
  If that amount of money cannot be made up by any combination of the coins, return -1.

  You may assume that you have an infinite number of each kind of coin.

  Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 
      11 = 5 + 5 + 1

  Example 2:
    Input: coins = [2], amount = 3
    Output: -1

  Example 3:
    Input: coins = [1], amount = 0
    Output: 0

  Example 4:
    Input: coins = [1], amount = 1
    Output: 1

  Example 5:
    Input: coins = [1], amount = 2
    Output: 2

  Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
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