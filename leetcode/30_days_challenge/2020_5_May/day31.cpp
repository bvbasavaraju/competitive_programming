/****************************************************
Date: May 31st

link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/
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
  Q: Edit Distance
  Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
  You have the following 3 operations permitted on a word:
  Insert a character
  Delete a character
  Replace a character

  Example 1:
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
      horse -> rorse (replace 'h' with 'r')
      rorse -> rose (remove 'r')
      rose -> ros (remove 'e')
 
  Example 2:
    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
      intention -> inention (remove 't')
      inention -> enention (replace 'i' with 'e')
      enention -> exention (replace 'n' with 'x')
      exention -> exection (replace 'n' with 'c')
      exection -> execution (insert 'u')
*/
class Solution 
{
public:
  int minDistance(string w1, string w2) 
  {
    int lw1 = w1.size();
    int lw2 = w2.size();
    
    vector<vector<int>> dp(lw1+1, vector<int>(lw2+1, 0));
    
    dp[0][0] = 0;
    for(int i = 1; i <= lw1; ++i)
      dp[i][0] = 1 + dp[i-1][0];  //  remove
    
    for(int j = 1; j <= lw2; ++j)
      dp[0][j] = 1 + dp[0][j-1];  // add
    
    for(int i = 1; i <= lw1; ++i)
    {
      for(int j = 1; j <= lw2; ++j)
      {
        if(w1[i-1] == w2[j-1])
        {
          dp[i][j] = dp[i-1][j-1];
        }
        else
        {
          //dp[i][j-1] - add
          //dp[i-1][j] - remove
          //dp[i-1][j-1] - replace
          dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
      }
    }
    
    return dp[lw1][lw2];
  }
};