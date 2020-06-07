/****************************************************
Date: June 7th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/
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
  Q: Coin Change 2

  You are given coins of different denominations and a total amount of money.
  Write a function to compute the number of combinations that make up that amount.
  You may assume that you have infinite number of each kind of coin.

  Example 1:
    Input: amount = 5, coins = [1, 2, 5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1

  Example 2:
    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.

  Example 3:
    Input: amount = 10, coins = [10] 
    Output: 1

  Note:
    You can assume that
      0 <= amount <= 5000
      1 <= coin <= 5000
      the number of coins is less than 500
      the answer is guaranteed to fit into signed 32-bit integer
*/

class Solution 
{
public:
  int change(int amount, vector<int>& coins) 
  {
    int l = coins.size();
    
    vector<int> dp(amount + 1);
    dp[0] = 1;
    
    for(int p = 0; p < l; ++p)
    {
      int coin = coins[p]; 
      for(int s = 1; s <= amount; ++s)
      {
        if(s == coin)
        {
          dp[s] += 1;
        }
        else if(s - coin > 0)
        {
          dp[s] += dp[s - coin];
        }
      }
    }
    
    return dp[amount];
  }
};