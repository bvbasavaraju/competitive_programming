/****************************************************
Date: July 29th

link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/548/week-5-july-29th-july-31st/3406/
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
  Q: Best Time to Buy and Sell Stock with Cooldown - wrong answer!

  Say you have an array for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
  (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
    + You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
    + After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
  
  Example:
    Input: [1,2,3,0,2]
    Output: 3 
    Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution 
{
public:
  int maxProfit(vector<int>& prices) 
  {
    int tx = 0; // 0 - buy, 1 - sell, 2 - cooldown
    
    int ans = 0;
    int l = prices.size();
    for(int i = 0 ; i < l; ++i)
    {
      int p = prices[i];
      switch(tx)
      {
        case 0:
          if((i < l-1) && (p < prices[i+1]))
          {
            ans -= p;
            tx++;
          }          
          break;
          
        case 1:
          if(i == l - 1)
          {
            ans += p;
            tx++;             
          }
          else
          {
            if((p - prices[i-1]) >= (prices[i+1] - p))
            {
              ans += p;
              tx++;   
            }
          }
          break;
          
        case 2:
        default:
          tx++;
          break;
      }
      
      tx %= 3;
    }
    
    return ans;
  }
};