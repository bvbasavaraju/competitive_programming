/****************************************************
Date: March 16th

link: https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3673/
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
  Q: Best Time to Buy and Sell Stock with Transaction Fee

  You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

  Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

  Example 1:
    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: 
      The maximum profit can be achieved by:
        - Buying at prices[0] = 1
        - Selling at prices[3] = 8
        - Buying at prices[4] = 4
        - Selling at prices[5] = 9
      The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

  Example 2:
    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6

  Constraints:
    1 < prices.length <= 5 * 104
    0 < prices[i], fee < 5 * 104
  
  Hide Hint #1  
    Consider the first K stock prices. At the end, the only legal states are that you don't own a share of stock, or that you do. 
    Calculate the most profit you could have under each of these two cases.
*/

class Solution 
{
  //TODO: need to memorise the position with buy or sold info to avoid TLE
// private:
//   void getMaxProfit(const vector<int>& prices, int p, int buy, int fee, int currentProfit, int& maxProfit)
//   {
//     if(p >= prices.size())
//     {
//       return;
//     }
    
//     if(!buy)
//     {
//       int newProfit = (currentProfit + prices[p] - fee);
//       maxProfit = max(maxProfit, newProfit);
        
//       getMaxProfit(prices, p+1, true, fee, newProfit, maxProfit);
//       getMaxProfit(prices, p+1, false, fee, currentProfit, maxProfit);
//     }
//     else
//     {
//       getMaxProfit(prices, p+1, false, fee, currentProfit-prices[p], maxProfit);
//       getMaxProfit(prices, p+1, true, fee, currentProfit, maxProfit);
//     }
//   }
  
public:
  int maxProfit(vector<int>& prices, int fee) 
  {
//     int ans = 0;    
//     getMaxProfit(prices, 0, true, fee, 0, ans);
    
//     return ans;
    int l = prices.size();
    
    int sold = 0;
    int notSold = INT_MIN;
    
    for(int i = 0; i < l; ++i)
    {
      int temp = sold;
      sold = max(sold, notSold+prices[i]);
      
      notSold = max(notSold, temp-prices[i]-fee);
    }
    
    return sold;
  }
};