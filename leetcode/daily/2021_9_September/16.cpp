/****************************************************
Date: September 16th

link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3977/
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
  Q: Spiral Matrix

  Given an m x n matrix, return all elements of the matrix in spiral order.

  Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]

  Example 2:
    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

  Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100

  Hide Hint #1  
    Well for some problems, the best way really is to come up with some algorithms for simulation. 
    Basically, you need to simulate what the problem asks us to do.
  
  Hide Hint #2  
    We go boundary by boundary and move inwards. That is the essential operation. 
    First row, last column, last row, first column and then we move inwards by 1 and then repeat. 
    That's all, that is all the simulation that we need.
    
  Hide Hint #3  
    Think about when you want to switch the progress on one of the indexes. If you progress on
      i
    out of
      [i, j]
    you'd be shifting in the same column. Similarly, by changing values for
      j
    , you'd be shifting in the same row. Also, keep track of the end of a boundary so that you can move 
    inwards and then keep repeating. It's always best to run the simulation on edge cases like a single column or 
    a single row to see if anything breaks or not.
*/

class Solution 
{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) 
  {
    int r = matrix.size();
    int c = matrix[0].size();
    
    int count = r*c;
    
    int i = 0;
    int j = 0;
    vector<int> ans;
    deque<char> dir = {'r','d','l','u'};
    while(count > 0)
    {
      bool changeDir = false;
      char d = dir.front();
      switch(d)
      {
        case 'r': // columns index will be moved towards 
          ans.push_back(matrix[i][j]);
          matrix[i][j++] = INT_MIN;
          if((j >= c) || (matrix[i][j] == INT_MIN))
          {
            j--;
            i++;
            changeDir = true;
          }
          break;
          
        case 'd': // rows index will be moved down
          ans.push_back(matrix[i][j]);
          matrix[i++][j] = INT_MIN;
          if((i >= r) || (matrix[i][j] == INT_MIN))
          {
            i--;
            j--;
            changeDir = true;
          }
          break;
          
        case 'l': // column index will be moved left
          ans.push_back(matrix[i][j]);
          matrix[i][j--] = INT_MIN;
          if((j < 0) || (matrix[i][j] == INT_MIN))
          {
            j++;
            i--;
            changeDir = true;
          }
            
          break;
          
        case 'u': //rows index will be moved up
          ans.push_back(matrix[i][j]);
          matrix[i--][j] = INT_MIN;
          if((i < 0) || (matrix[i][j] == INT_MIN))
          {
            i++;
            j++;
            changeDir = true;
          }
          break;
          
        default:
          break;
      }
      
      if(changeDir)
      {
        dir.pop_front();
        dir.push_back(d);
      }
      
      count--;
    }
    
    return ans;
  }
};