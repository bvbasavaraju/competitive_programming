/****************************************************
Date: June 29th

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
  Q: Unique Paths

  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
  The robot can only move either down or right at any point in time. 
  The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

  How many possible unique paths are there?

  Above is a 7 x 3 grid. How many possible unique paths are there?

  Example 1:
    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right
  
  Example 2:
    Input: m = 7, n = 3
    Output: 28

  Constraints:
    1 <= m, n <= 100
    It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
*/

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
      if((m == 0) && (n == 0))
      {
        return 0;
      }
      else if((m == 0) || (n == 0))
      {
        return 0;
      }
      
      vector< vector<int> > uniquePaths(m, vector<int>(n, 0));
      
      uniquePaths[0][0] = 1;
      for(int r = 0; r < m; r++)
      {
        for(int c = 0; c < n; c++)
        {
          if(r == 0)
          {
            if(c > 0)
            {
              uniquePaths[r][c] += uniquePaths[r][c - 1];
            }
          }
          else
          {
            if(c == 0)
            {
              uniquePaths[r][c] += uniquePaths[r - 1][c];
            }
            else
            {
              uniquePaths[r][c] = uniquePaths[r][c - 1] + uniquePaths[r - 1][c];
            }
          }
        }
      }
      
      return uniquePaths[m-1][n-1];
    }
};