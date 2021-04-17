/****************************************************
Date: April 16th

link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/595/week-3-april-15th-april-21st/3709/
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
  Q: Number of Submatrices That Sum to Target

  Given a matrix and a target, return the number of non-empty submatrices that sum to target.
  A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
  Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

  Example 1:
    Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
    Output: 4
    Explanation: 
      The four 1x1 submatrices that only contain 0.

  Example 2:
    Input: matrix = [[1,-1],[-1,1]], target = 0
    Output: 5
    Explanation:
      The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

  Example 3:
    Input: matrix = [[904]], target = 0
    Output: 0

  Constraints:
    1 <= matrix.length <= 100
    1 <= matrix[0].length <= 100
    -1000 <= matrix[i] <= 1000
    -10^8 <= target <= 10^8

  Hide Hint #1  
    Using a 2D prefix sum, we can query the sum of any submatrix in O(1) time. 
    Now for each (r1, r2), we can find the largest sum of a submatrix 
    that uses every row in [r1, r2] in linear time using a sliding window.
*/

class Solution 
{
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
  {
    int ans = 0;
    int r = matrix.size();
    int c = matrix[0].size();
    
    for (int i = 0; i < r; i++)
    {
      for (int j = 1; j < c; j++)
      {
        matrix[i][j] += matrix[i][j - 1];
      }
    }

    unordered_map<int, int> counter;
    for (int i = 0; i < c; i++) 
    {
      for (int j = i; j < c; j++) 
      {
        counter = {{0,1}};
        
        int cur = 0;
        for (int k = 0; k < r; k++) 
        {
          cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
          ans += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
          counter[cur]++;
        }
      }
    }
    return ans;
  }
};