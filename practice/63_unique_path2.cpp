#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  int uniquePathsWithObstacles(vector<vector<int>>& og) 
  {
    int r = og.size();
    int c = og[0].size();
    
    vector< vector<int> > ans(r, vector<int>(c, 0));
    
    for(int i = 0; i < r; ++i)
    {
      for(int j = 0; j < c; ++j)
      {
        if((og[i][j] == 1))
        {
          continue;
        }
        
        if(i == 0 && j == 0)
        {
          ans[i][j] = 1;
          continue;
        }
        
        if(i == 0)
        {
          ans[i][j] = ans[i][j-1] == 1 ? 1 : 0; 
        }
        else if(j == 0)
        {
          ans[i][j] = ans[i-1][j] == 1 ? 1 : 0;
        }
        else
        {
          ans[i][j] += ans[i-1][j] + ans[i][j-1];
        }
      }
    }
    
    return ans[r-1][c-1];
  }
};