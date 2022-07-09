#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
  vector<vector<int>> generateMatrix(int n) 
  {
    vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
    
    int val = 1;
    int r = 0;
    int c = 0;
    int direction = 0;  // 0 -> right, 1 -> down, 2 -> left, 3 ->up
    while(val <= (n*n))
    {
      ans[r][c] = val;
      
      val++;
      
      switch(direction)
      {
        case 0:
          if(c+1 >= n || ans[r][c+1] != INT_MAX)
          {
            direction++;
            r++;  //prepare for next
          }
          else
          {
            c++;
          }
          break;
          
        case 1:
          if(r+1 >= n || ans[r+1][c] != INT_MAX)
          {
            direction++;
            c--;  //prepare for next
          }
          else
          {
            r++;
          }
          break;
          
        case 2:
          if(c-1 < 0 || ans[r][c-1] != INT_MAX)
          {
            direction++;
            r--;  //prepare for next
          }
          else
          {
            c--;
          }
          break;
          
        case 3:
          if(r-1 < 0 || ans[r-1][c] != INT_MAX)
          {
            direction++;
            c++;  //prepare for next
          }
          else
          {
            r--;
          }
          break;
          
        default:
          break;
      }
      
      direction = direction % 4;  // there can only be 4 directions
    }
    
    return ans;
  }
};