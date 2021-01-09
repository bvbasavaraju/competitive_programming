/****************************************************
Date: June 9th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
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
  Q: Is Subsequence

  Given a string s and a string t, check if s is subsequence of t.
  A subsequence of a string is a new string which is formed from the 
  original string by deleting some (can be none) of the characters without disturbing 
  the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

  Follow up:
  If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, 
  and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

  Credits:
  Special thanks to @pbrother for adding this problem and creating all test cases.

  Example 1:
    Input: s = "abc", t = "ahbgdc"
    Output: true

  Example 2:
    Input: s = "axc", t = "ahbgdc"
    Output: false

  Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 10^4
    Both strings consists only of lowercase characters.
*/

class Solution 
{
public:
  bool isSubsequence(string s, string t) 
  {
    int r = s.size();
    int c = t.size();
    
    vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
    
    for(int i = 1; i <= r; ++i)
    {
      for(int j = 1; j <= c; ++j)
      {
        if(s[i-1] == t[j-1])
        {
          dp[i][j] = 1 + dp[i-1][j-1];
        }
        else
        {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
    
    return (dp[r][c] == r) ? true : false;
  }
};