/****************************************************
Date: April 21th

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
  Q: Triangle

  Given a triangle array, return the minimum path sum from top to bottom.

  For each step, you may move to an adjacent number of the row below. More formally, 
  if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

  Example 1:
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: 
      The triangle looks like:
         2
        3 4
       6 5 7
      4 1 8 3
      The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


  Example 2:
    Input: triangle = [[-10]]
    Output: -10

  Constraints:
    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -104 <= triangle[i][j] <= 104

  Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

class Solution 
{
public:
  int minimumTotal(vector<vector<int>>& triangle) 
  {
    int l = triangle.size();
    
    for(int i = 0; i < l; ++i)
    {
      int cols = triangle[i].size();
      for(int j = 0; j < cols; ++j)
      {
        if(i == 0)
        {
          triangle[i].push_back(triangle[0][0]);
          continue;
        }
        
        if(j == 0)
        {
          triangle[i][0] += triangle[i-1][0];
        }
        else if(j == cols-1)
        {
          triangle[i][j] += triangle[i-1][j-1];
        }
        else
        {
          triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }
      }
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < l; ++i)
    {
      ans = min(ans, triangle[l-1][i]);
    }
    
    return ans;
  }
};