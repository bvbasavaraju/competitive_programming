/*
  Q: 566. Reshape the Matrix
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

class Solution 
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
  {
    int ro = mat.size();
    int co = mat[0].size();
    
    if((ro == r && co == c) || (ro*co != r*c))
    {
      return mat;
    }
    
    int ra = 0; 
    int ca = 0;
    vector< vector<int> > ans(r, vector<int>(c, 0));
    for(int i = 0; i < ro; ++i)
    {
      for(int j = 0; j < co; ++j)
      {
        ans[ra][ca] = mat[i][j];
        ca++;
        if(ca >= c)
        {
          ra++;
          ca = 0;
        }
      }
    }
    
    return ans;
  }
};