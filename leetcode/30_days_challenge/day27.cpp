/****************************************************
Date: April 27th

link: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3312/
****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
  Q: Maximal Square
  Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

  Example:

  Input: 
  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

  Output: 4
*/

class Solution 
{
public:
  int maximalSquare(vector<vector<char>>& m) 
  {
    if(m.empty())
    {
      return 0;
    }
    
    int r = m.size();
    int c = m[0].size();
    
    int ans = 0;
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if(i == 0 && j == 0)
        {
          dp[i][j] = m[i][j] - '0';
        }
        else if(i == 0)
        {
          dp[i][j] = m[i][j] == '0' ? 0 : m[i][j] - '0';
        }
        else if(j == 0)
        {
          dp[i][j] = m[i][j] == '0' ? 0 : m[i][j] - '0';
        }
        else
        {
          if(m[i][j] - '0' > 0)
          {
            int low = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            dp[i][j] = 1 + low;
          }
        }
        
        ans = max(ans, dp[i][j]);
      }
    }
    
    return ans * ans;
  }
};
