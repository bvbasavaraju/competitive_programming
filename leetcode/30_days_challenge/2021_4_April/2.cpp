/****************************************************
Date: April 2nd

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
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
  Q: Ones and Zeroes

  You are given an array of binary strings strs and two integers m and n.
  Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
  A set x is a subset of a set y if all elements of x are also elements of y.

  Example 1:
    Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    Output: 4
    Explanation: 
      The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
      Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
      {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

  Example 2:
    Input: strs = ["10","0","1"], m = 1, n = 1
    Output: 2
    Explanation:
      The largest subset is {"0", "1"}, so the answer is 2.

  Constraints:
    1 <= strs.length <= 600
    1 <= strs[i].length <= 100
    strs[i] consists only of digits '0' and '1'.
    1 <= m, n <= 100
*/

class Solution 
{
public:
  int findMaxForm(vector<string>& strs, int m, int n) 
  {
    vector< vector<int> > dp(m+1, vector<int>(n+1, 0));
      
    for(string& s : strs)
    {
      int zeros = 0;
      int ones = 0;
      for(int ch : s)
      {
        if(ch == '0')
        {
          zeros++;
        }
        else
        {
          ones++;
        }
      }
      
      for(int i = m; i >= zeros; --i)
      {
        for(int j = n; j >= ones; --j)
        {
          dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }
      }
    }
    
    return dp[m][n];
  }
};