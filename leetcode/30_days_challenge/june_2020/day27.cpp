/****************************************************
Date: June 27th

link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3372/
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
#include <string_view>

using namespace std;

/*
  Q: Perfect Squares

  Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

  Example 1:
    Input: n = 12
    Output: 3 
    Explanation: 12 = 4 + 4 + 4.

  Example 2:
    Input: n = 13
    Output: 2
    Explanation: 13 = 4 + 9.
*/

class Solution 
{
public:
  int numSquares(int n) 
  {
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        dp[i]=i;
        for(int j=1;j<=sqrt(i);j++)
        {
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    return dp[n];
  }
};

int main()
{
  {
    Solution s;
    int ans = s.numSquares(9876);
  }

  return 0;
}