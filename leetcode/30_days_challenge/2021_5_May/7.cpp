/****************************************************
Date: May 7th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
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
  Q: Delete Operation for Two Strings

  Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
  In one step, you can delete exactly one character in either string.

  Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation:
      You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

  Example 2:
    Input: word1 = "leetcode", word2 = "etco"
    Output: 4

  Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
*/

class Solution 
{
private:
  int LCS(string w1, string w2) 
  {
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) 
    {
      for (int j = 1; j <= m; j++) 
      {
        dp[i][j] = w1[i-1] == w2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
      }
    }

    return dp[n][m];
  }
  
public:
  int minDistance(string word1, string word2) 
  {
    int lcs = LCS(word1, word2);
    return word1.size() + word2.size() - (2 * lcs);
  }
};
