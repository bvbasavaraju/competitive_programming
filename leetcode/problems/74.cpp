/*
  Q: 74. Search a 2D Matrix
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

class Solution 
{
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) 
  {
    int row = matrix.size();
    int col = matrix[0].size();
    
    int l = 0;
    int h = (row * col) - 1;
    
    while(l <= h)
    {
      int m = (h+l)/2;
      
      int r = m / col;
      int c = m % col;
      
      if(matrix[r][c] == target)
      {
        return true;
      }
      else if(matrix[r][c] > target)
      {
        h = m-1;
      }
      else
      {
        l = m+1;
      }
    }
    
    return false;
  }
};