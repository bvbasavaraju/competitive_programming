/****************************************************
Date: October 1st

https://leetcode.com/problems/longest-common-subsequence/
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
  Q: Longest Common Subsequence
  
  Given two strings text1 and text2, return the length of their longest common subsequence. 
  If there is no common subsequence, return 0.

  A subsequence of a string is a new string generated from the original string with some characters (can be none) 
  deleted without changing the relative order of the remaining characters.

  For example, "ace" is a subsequence of "abcde".
  A common subsequence of two strings is a subsequence that is common to both strings.

  Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation:
      The longest common subsequence is "ace" and its length is 3.

  Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation:
      The longest common subsequence is "abc" and its length is 3.

  Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation:
      There is no such common subsequence, so the result is 0.

  Constraints:
    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/

class Solution 
{
public:
  int longestCommonSubsequence(string t1, string t2) 
  {
    int t1_l = t1.size();
    int t2_l = t2.size();
    
    vector<vector<int>> dp(t1_l, vector<int>(t2_l, 0));
    for(int i = 0; i < t1_l; ++i)
    {
      for(int j = 0; j < t2_l; ++j)
      {
        if(i == 0 && j == 0)
        {
          dp[i][j] = t1[i] == t2[i] ? 1 : 0;
        }
        else if(i == 0)
        {
          dp[i][j] = max(dp[i][j-1], (t1[0] == t2[j] ? 1: 0));
        }
        else if(j == 0)
        {
          dp[i][j] = max(dp[i-1][j], (t1[i] == t2[0] ? 1 : 0));
        }
        else
        {
          if(t1[i] != t2[j])
          {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
          else
          {
            dp[i][j] = 1 + dp[i-1][j-1];
          }
        }
      }
    }
    
    return dp[t1_l-1][t2_l-1];
  }
};