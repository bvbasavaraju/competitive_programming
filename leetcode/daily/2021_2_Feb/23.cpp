/****************************************************
Date: Feb 23rd

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3649/
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
  Q: Search a 2D Matrix II

  Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

  Integers in each row are sorted in ascending from left to right.
  Integers in each column are sorted in ascending from top to bottom.

  Example 1:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true

  Example 2:
    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false

  Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
*/

class Solution 
{
private:
  bool isFound(vector<int>& r, int t)
  {
    int l = 0;
    int h = r.size()-1;
    
    while(l <= h)
    {
      int m = l + (h-l)/2;
      if(r[m] == t)
      {
        return true;
      }
      
      if(r[m] < t)
      {
        l = m+1;
      }
      else
      {
        h = m-1;
      }
    }
    
    return false;
  }
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) 
  {
    int r = 0;
    int c = matrix[0].size() - 1;
    while(r < matrix.size() && c >= 0)
    {
      if(matrix[r][c] == target)
      {
        return true;
      }
      
      if(matrix[r][c] > target)
      {
        c--;
      }
      else
      {
        r++;
      }
    }
    
    return false;
    //O(rlogc) solution
//     int r = matrix.size();
//     int c = matrix[0].size();
    
//     for(int i = 0; i < r; ++i)
//     {
//       if(isFound(matrix[i], target))
//       {
//         return true;
//       }
//     }
    
//     return false;
  }
};