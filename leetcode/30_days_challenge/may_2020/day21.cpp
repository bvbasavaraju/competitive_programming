/****************************************************
Date: May 21th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/
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
  Q: Count Square Submatrices with All Ones

  Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

  Example 1:
    Input: matrix =
    [
      [0,1,1,1],
      [1,1,1,1],
      [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.

  Example 2:
    Input: matrix = 
    [
      [1,0,1],
      [1,1,0],
      [1,1,0]
    ]
    Output: 7
    Explanation: 
    There are 6 squares of side 1.  
    There is 1 square of side 2. 
    Total number of squares = 6 + 1 = 7.

  Constraints:
    1 <= arr.length <= 300
    1 <= arr[0].length <= 300
    0 <= arr[i][j] <= 1

  Hide Hint #1  
    Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).
  Hide Hint #2  
    Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.
*/
class Solution 
{
public:
  int countSquares(vector<vector<int>>& m) 
  {
    int ans = 0;
    
    int r = m.size();
    if(r == 0)
    {
      return ans;
    }
    
    int c = m[0].size();
    if(c == 0)
    {
      return ans;
    }
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0 ; j < c; ++j)
      {
        if(m[i][j] == 0)
        {
          continue;
        }
        
        if(i > 0 && j > 0)
        {          
          m[i][j] += min({m[i - 1][j - 1], m[i-1][j], m[i][j-1]});
        }
        
        ans += m[i][j];
      }
    }
    
    return ans;
  }
};